/**
 * K&R 6.3
 *
 * This program counts words in standard input, displaying line numbers words
 * occur in.
 *
 * By default, `words` file is an «ignore-list» — words listed in it
 * will not be counted. This behaviour may be inverted using the `-x`
 * option (see below). Please note that changing `words` file requires
 * recompiling program afterwards :) This feature is most likely to be
 * removed in future versions (`grep` is a better way to filter
 * output).
 *
 * Usage:
 *     ./id-count [-x] [-l n] [-c]
 *
 * The program is expected to be used in a pipe, for example:
 *
 *     $ cat /usr/src/linux/drivers/net/8139cp.c | ./id-count -l 6
 *     
 * Possible program options:
 * `-l`    for specifying minimum word length.
 * `-x`    to count only ignored words :)
 * `-c`    to make string comparison ignore letter case.
 *
 * By default, only words with length >= DEFAULT_MIN_LENGTH are
 * counted!  Maximum word length is limited by MAXWORD.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "getty.h"
#include "wordtree.h"
#include "binsearch.h"
#include "compare.h"

#define MAXWORD 512

#define WORDS_COUNT (sizeof(words) / sizeof(words[0]) - 1)
#define DEFAULT_MIN_LENGTH 5

char * words[] = 
  {
    #include "words.inc"
  };

int main(int argc, char * argv[])
{
  /* Minimal length for word to be counted */
  int min_length = DEFAULT_MIN_LENGTH;

  /* Current line */
  int line = 1;
  
  /*
    If 1, only words listed in words[] will be counted!
    min_length still respected.
  */
  int invert_rule = 0;

  int ignore_case = 0;

  char c;
  char * current_word = malloc(sizeof(char) * MAXWORD);

  /* Word tree */
  struct tnode * tree = NULL;

  while (--argc > 0 && **++argv == '-')
    {
      {
        while (c = *++(argv[0]))
          {
            switch (c)
              {
              case 'l':
                min_length = atoi(*++argv);
                argc--;
                break;
              case 'x':
                invert_rule = 1;
                break;
              case 'c':
                ignore_case = 1;
                break;
              default:
                printf("Error: unrecognized option.\n");
                return 1;
              }
          }
      }
    }

  while ((c = getword(current_word, MAXWORD)) != EOF)
    {
      if (c == '\n')
        line++;
      else
        {
          if (ignore_case)
            strtolower(current_word);
          
          if ((isalnum(c) || c == '#' || c == '_') && strlen(current_word) >= min_length)
            if (binsearch(current_word, words, WORDS_COUNT) == -1)
              {
                if (!invert_rule)
                  tree = insertNode(tree, current_word, line);
              }
            else
              if (invert_rule)
                tree = insertNode(tree, current_word, line);                
        }
      
    }

  printTree(tree);

  return 0;
}


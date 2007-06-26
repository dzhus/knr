/**
 * K&R 6.2
 *
 * Program performs counting variables (_grouped_ by first several
 * name letters) in C source files.  This is an advanced version of
 * `id-count-pro` program (though in a K&R it comes right before it).
 *
 * Sample program output:
 *
 *     Group vlgrp, 7 variables:
 *	    Variable vlgrp, occured 7 times:
 *		Line 364, 1 times
 *		Line 437, 1 times
 *		Line 451, 1 times
 *		Line 452, 1 times
 *		Line 478, 1 times
 *		Line 479, 1 times
 *		Line 786, 1 times
 *     Group wakeup, 3 variables:
 *     	    Variable wakeup, occured 3 times:
 *		Line 296, 1 times
 *		Line 297, 1 times
 *      	Line 298, 1 times
 *     Group watchd, 1 variables:
 *           Variable watchdog_timeo, occured 1 times:
 *		Line 1944, 1 times
 *
 * This program and `id-count-pro` probably should be merged, as
 * they're already have big portions of the same code.
 *
 * 
 * Respects the following options:
 * `-m`    minimal identifier length to be counted
 * `-l`    variable group tag length
 * `-c`    to make string comparison ignore letter case.
 *
 * Limitations
 * - maximum word length is limited (see MAXWORD macro)
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "getty.h"
#include "vartree.h"
#include "binsearch.h"

#define MAXWORD 512

#define WORDS_COUNT (sizeof(ignore_words) / sizeof(ignore_words[0]))
#define DEFAULT_MIN_LENGTH 5
#define DEFAULT_TAG_LENGTH 6

char * ignore_words[] = 
  {
    #include "ignore_words.inc"
  };

void strtolower(char * s);

int main(int argc, char * argv[])
{
  /* Minimal length for word to be counted */
  int min_length = DEFAULT_MIN_LENGTH;

  /* Length of tag for each variable group */
  int tag_length = DEFAULT_TAG_LENGTH;

  int ignore_case = 0;

  char c;

  while (--argc > 0 && **++argv == '-')
    {
      {
        while (c = *++(argv[0]))
          {
            switch (c)
              {
              case 'm':
                min_length = atoi(*++argv);
                argc--;
                break;
              case 'c':
                ignore_case = 1;
                break;
              case 'l':
                tag_length = atoi(*++argv);
                argc--;
                break;
              default:
                printf("Error: unrecognized option.\n");
                return 1;
              }
          }
      }
    }

  /* Current line */
  int line = 1;

  char * current_word = malloc(sizeof(char) * (MAXWORD + 1));
  
  /* Word tree */
  Group * tree = NULL;

  /* Group tag for current variable */
  char * tag = malloc(sizeof(char) * (tag_length + 1));
  
  while ((c = getword(current_word, MAXWORD)) != EOF)
    if (c == '\n')
      line++;
    else
      {
        if (ignore_case)
          strtolower(current_word);

        strncpy(tag, current_word, tag_length);
        
        if ((isalnum(c) || c == '_') && strlen(current_word) >= min_length)
          if (binsearch(current_word, ignore_words, WORDS_COUNT) == -1)
            tree = insertGroup(tree, tag, current_word, line);                
      }

  printGroup(tree);
  
  return 0;
}

void strtolower(char * s)
{
  while (*s++ = tolower(*s))
    ;
}

/**
 * K&R 6.4
 *
 * Count word frequency in stdout and print out sorted results.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "word_list.h"
#include "getty.h"

#define MAXWORD 512

int main(int argc, char * argv[])
{
  /* Ptr to first list element */
  wordHead * head = (wordHead *)malloc(sizeof(wordNode));
  wordNode * tree = NULL;
  head->entry = tree;

  char * current_word = (char *)malloc(sizeof(char)*MAXWORD);
  char c;
  while ((c = getword(current_word, MAXWORD)) != EOF)
    if (isalnum(c))
        tree = insertWordNode(current_word, tree, head);
  
  printTreeByFreq(head->entry);
  
  return 0;
}

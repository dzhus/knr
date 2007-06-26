#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "word_list.h"

#ifdef DEBUG
#define DPRINT(mesg, ...) fprintf(stderr, mesg, __VA_ARGS__)
#else
#define DPRINT(mesg, ...)
#endif

/**
   Get a tree node for word
*/
wordNode * insertWordNode(char * word, wordNode * root, wordHead * head)
{
  int cmp;
  
  DPRINT("Got %s\n", word);
  
  if (root == NULL)
    {
      root = newWordNode(word);
      /** add entry to list */
      root->freq++;
      root->next = head->entry;
      head->entry = root;
      if (root->next)
        DPRINT("%p (%s, %d) -> %p (%s, %d)\n",
               root, root->word, root->freq,
               root->next, root->next->word, root->next->freq);
      
    }
  else
    if ((cmp = strcmp(word, root->word)) == 0)
      {
        /** increase word count in list */
        root->freq++;
        /** reorder part of list if needed */
        // while (root->next != NULL && (root->freq > root->next->freq))
          {
            /** @todo */
          }
      }
    else
      if (cmp > 0)
        root->right = insertWordNode(word, root->right, head);
      else
        root->left = insertWordNode(word, root->left, head);
  
  return root;
}

wordNode * newWordNode(char * name)
{
  wordNode * t = (wordNode *)malloc(sizeof(wordNode));
  t->left = t->right = t->next = NULL;
  t->freq = 0;
  t->word = strdup(name);
  return t;
}

/**
   Normally, head.entry should be passed as 'root' here
*/
void printTreeByFreq(wordNode * n)
{
  if (n->next != NULL)
    printTreeByFreq(n->next);
  printf("%s (%d)\n", n->word, n->freq);
}

void printTree(wordNode * n)
{
  if (n != NULL)
    {
      printTree(n->left);

      printf("%s (%d)\n", n->word, n->freq);
      
      printTree(n->right);
    }
}

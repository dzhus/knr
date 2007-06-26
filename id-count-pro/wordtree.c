#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "wordtree.h"

/* Returns a pointer to a tree with a new word inserted */
struct tnode * insertNode(struct tnode * p, char * word, int line)
{
  int cmp;

  if (p == NULL)
    {
      p = createNode(word, line);
    }
  else    
    if ((cmp = strcmp_e(p->word, word)) != 0)
      if (cmp > 0)
        p->left = insertNode(p->left, word, line);
      else
        p->right = insertNode(p->right, word, line);
    else
      {
        p->count++;
        p->line = newLine(p->line, line);
      }

  return p;
}

/* Returns a pointer to a new node */
struct tnode * createNode(char * word, int line)
{
  struct tnode * node;
  
  node = allocateNode();
  node->left = node->right = NULL;
  node->count = 1;

  node->line = newLine(node->line, line);
    
  node->word = (char *)malloc(strlen(word) + 1);
  strcpy(node->word, word);

  return node;
}

/* Returns a pointer to a memory block for tnode */
struct tnode * allocateNode(void)
{
  return (struct tnode *)malloc(sizeof(struct tnode));
}

/*
  Add a new line to the list of lines the word occurs in. If a word
  occurs in the same line several times, corresponding line number
  will be stored several times, too.
*/
struct word_line * newLine(struct word_line * old_line, int new_line)
{
  struct word_line * new = (struct word_line *)malloc(sizeof(struct word_line));

  new->number = new_line;
  new->prev = old_line;
  
  return new;
}

/* Print data on node */
void printNode(struct tnode * node)
{
  printf("%s %d:", node->word, node->count);
  printLines(node->line);
  putchar('\n');
}

/* Print the list of lines the node occurs in */
void printLines(struct word_line * line)
{
  if (line->prev != NULL)
      printLines(line->prev);
  
  printf(" %d", line->number);
}

/* Print the whole tree sorted */
void printTree(struct tnode * root)
{
  if (root != NULL) 
    {
      printTree(root->left);
      printNode(root);
      printTree(root->right);
    }
}

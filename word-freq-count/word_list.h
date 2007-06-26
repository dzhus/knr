#ifndef WORDLIST_INC
#define WORDLIST_INC

typedef struct tnode
{
  char * word;
  struct tnode * left, * right;
  struct tnode * next;
  int freq;
} wordNode;

typedef struct thead
{
  struct tnode * entry;
} wordHead;

wordNode * insertWordNode(char * word, wordNode * root, wordHead * head);
wordNode * newWordNode(char * name);

void printTreeByFreq(wordNode * root);

#endif

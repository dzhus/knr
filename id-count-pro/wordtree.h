#ifndef WORDTREE_INC
#define WORDTREE_INC

struct word_line
{
  int number;
  struct word_line * prev;
};
  
struct tnode
{
  char * word;
  int count;
  struct word_line * line;
  struct tnode * left;
  struct tnode * right;
};

struct tnode * insertNode(struct tnode * root, char * word, int line);
struct tnode * createNode(char * word, int line);
struct tnode * allocateNode(void);

struct word_line * newLine(struct word_line * old_line, int new_line);

void printTree(struct tnode * root);
void printNode(struct tnode * node);
void printLines(struct word_line * line);

#endif

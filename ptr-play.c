#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
  char word;
  int count;
};

void updateNode(struct node * ptr);
void printNode(struct node * ptr);
  
int main (void)
{
  struct node * ptr;
  int i;
  printf("%p\n", ptr);
  ptr = (struct node *)malloc(sizeof(struct node));
  printf("%p\n", ptr);
  ptr->word = '0';
  ptr->count = 5;
  
  for (i = 0; i < 10; i++)
    {
      updateNode(ptr);
      printNode(ptr);
    }
  
  return 0;
}

void updateNode(struct node * ptr)
{
  /* изменение адреса указателя ptr НЕ изменит адрес указателя в вызвающей функции!
     можно изменить ЗНАЧЕНИЕ, на которое ссылается указатель, так, чтобы это изменение отразилось и
     в вызывающей функции, но для создания нового указателя нужно возвращать его из функции явно в
     вызывающую программу */
  ptr = (struct node *)malloc(sizeof(struct node));
  ptr->count++;
  ptr->word = '0' + 2 * ptr->count;
  printf("Inside: "); printNode(ptr);
}

void printNode(struct node * ptr)
{
  printf("Node at %p: %c, %d\n", ptr, ptr->word, ptr->count);
}

  

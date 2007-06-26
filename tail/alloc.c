#include <stdio.h>
#define ALLOCBUF_SIZE 1024*1024*10

static char allocbuf[ALLOCBUF_SIZE];
static char *allocp = allocbuf;

char * alloc(int length)
{
  if (allocp - allocbuf + length < ALLOCBUF_SIZE)
    {
      allocp += length;
      return allocp - length;
    }
  else
    return NULL;
}

void allocfree(char *p)
{
  if (p < allocbuf + ALLOCBUF_SIZE)
      allocp = p;
}

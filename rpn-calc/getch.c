#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c)
{
  if (bufp >= BUFSIZE)
    printf("Ungetch: too many characters.\n");
  else buf[bufp++] = c;
}

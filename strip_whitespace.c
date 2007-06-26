#include <stdio.h>

int main ()
{
  char c;
  while ((c = getchar()) != EOF)
    switch (c)
      {
      case '\t':
      case ' ':
      case '\n':
        break;
      default:
        putchar(c);
        break;
      }
}

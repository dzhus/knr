/**
 * K&R 7.1
 */

#include <ctype.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int (*conv)(int) = NULL;
  char c;

  while ((c = (*argv[0]++)) && !conv)
    if (isalpha(c))
        conv = (isupper(c) ? toupper : tolower);

  while ((c = getchar()) != EOF)
    putchar((*conv)(c));

  return 0;
}

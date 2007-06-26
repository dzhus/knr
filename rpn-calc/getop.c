#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getop(char s[])
{
  int i = 0, c;
  static char p = EOF;

  while ((s[i++] = c = (p == EOF) ? getch() : p) == ' ' || c == '\t')
    ;
  s[i] = '\0';
    
  /* Negative number? */
  if (!isdigit(c) && c != '.')
    {
      if (c == '-' && isdigit(s[i] = c = getch()))
        ;
      else
        return s[0];
    }
  
  if (isdigit(c))
    while (isdigit(s[++i] = c = getch()))
      ;
  if (c == '.')
    while (isdigit(s[++i] = c = getch()))
      ;

  s[i] = '\0';

  if (c != EOF)
    p = c;
  return NUMBER;
}

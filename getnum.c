/**
 * K&R 5.1, 5.2
 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(char);

int getint(int *pn)
{
  int c, sign;
  
  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
      ungetch(c);
      return 0;
    }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  if (!isdigit(c))
    {
      ungetch(c);
      return 0;
    }
    
  for (*pn = 0; isdigit(c); c = getch())
    *pn = *pn * 10 + (c - '0');
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int getfloat(double *pn)
{
  int c, sign, e;
  
  while (isspace(c = getch()))
    ;
  if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
      ungetch(c);
      return 0;
    }
  
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-')
    c = getch();
  if (!isdigit(c))
    {
      ungetch(c);
      return 0;
    }
    
  for (*pn = 0; isdigit(c); c = getch())
    *pn = *pn * 10 + (c - '0');

  if (c == '.')
    c = getch();
  if (!isdigit(c))
    {
      ungetch(c);
      return c;
    }
  for (e = 10; isdigit(c); c = getch(), e *= 10)
    {
      *pn = *pn + (c - '0')/1.0/e;
    }
  *pn *= sign;
  if (c != EOF)
    ungetch(c);
  return c;
}

int main(void)
{
  double a[10];
  int c;
  c = getfloat(&a[0]);
  printf("%f %d\n", a[0], c);
  return 0;
}


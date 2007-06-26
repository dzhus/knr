/**
 * K&R 3-4
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char s[])
{
  int c, i, j;

  for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
}

/* plain */
void itoa(long int n, char s[])
{
  int i, sign;
  long m;

  m = n;
  
  if((sign = n) < 0)
    n = -n;
  i = 0;

  do
    {
      s[i++] = abs(m % 10) + '0';
    }
  while (m /= 10);
  
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

/* recursive */
void itoa2(long int n, char s[])
{
  static int i;
  int top = (i == 0) ? 1 : 0;
    
  if (n < 0)
    {
      s[i++] = '-';
      n = -n;
    }

  if (n / 10)
    itoa2(n / 10, s);
  s[i++] = n % 10 + '0';
  s[i] = '\0';
  if (top)
    i = 0;
}

int main(void)
{
  char s1[25], s2[25];
  signed long i;
  for (i = -INT_MAX; i < INT_MAX; i++)
    {
      itoa(i, s1);
      itoa2(i, s2);
      if (strcmp(s1, s2))
        {
          putchar('\a');
          return 1;
        }
    }
  return 0;
}

/**
 * K&R 3.5
 */

#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
void reverse(char s[]);

int main(void)
{
  char s[10];
  itob(0xABCDEF, s, 16);
  printf("%s", s);
}

void reverse(char s[]) 
{
  int c, i, j;

  for (i = 0, j = strlen(s)-1; i < j; i++, j--) 
    {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
    }
}


void itob(int n, char s[], int b)
{
  int i = 0, r;
  if (n < 0)
    {
      n = -n;
      s[i++] = '-';
    }

  do
    {
      if ((r = n % b) < 10)
        s[i++] = '0' + r;
      else
        s[i++] = 'A' + r - 10;
      
      n = n / b;
    }
  while (n > b - 1);
  
  if (n != 0)
    if (n < 10)
      s[i++] = '0' + n;
    else
      s[i++] = 'A' + n - 10;

  s[i] = '\0';

  reverse(s);
}

      

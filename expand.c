/**
 * K&R 3-3
 */

#include <stdio.h>
#include <string.h>
#define BUF 100

void expand(char s1[], char s2[]);

int main (void)
{
  char s1[BUF] = "a-m-z-m-a", s2[BUF];
  
  expand(s1, s2);
  printf("%s expanded to %s\n", s1, s2);
}
/*     char *s[] = { "a-z-", "z-a-", "-1-6-", */
/*                   "a-ee-a", "a-R-L", "1-9-1", */
/*                   "5-5", NULL }; */

void expand(char s1[], char s2[])
{
  int i, j = 0, k;
  char from, to, c;
  
  for (i = 0; i < strlen(s1); i = k + 1)
    {
      from = to = s1[i];
      for (k = i; s1[k+1] == '-' && (k + 1 != strlen(s1) - 1); k += 2)
        to = s1[k+2];
      for (c = from; c <= to; c++)
        s2[j++] = c;
    }
  s2[j] = '\0';
}


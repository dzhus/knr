/**
 * K&R 2-5
 **/

#include <stdio.h>

int any (char s1[], char s2[]) 
{
  int i = 0, j = 0;

  for (i = 0; s1[i] != '\0'; i++)
    {
      for (j = 0; s2[j] != '\0'; j++) 
        {
          if (s1[i] == s2[j])
            return i;
        }
    }
  return -1;
}

int main () 
{
  char a[] = "testing";
  char b[] = "gn";

  printf("%d", any(a, b));
}

  

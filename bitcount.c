/**
 * K&R 2-9
 **/

#include <stdio.h>

unsigned long int bitcount (signed long x)
{
  int k = 0;
  while (x != 0)
    {
      x &= x-1;
      k++;
    }

  return k;
}

int main () 
{
  int i;
  for (i=0; i<=256; i++)
    {
      printf("%u\n", bitcount(i));
    }
}

  

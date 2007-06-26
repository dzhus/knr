/**
 * K&R 4.14
 */

#include <stdio.h>

/* Note that temp variable does not conflict with user's variables with the same name */
#define swap(x,y) \
  {               \
    int temp;     \
    temp = x;     \
    x = y;        \
    y = temp;     \
  }

int main(void)
{
  int a = 5, b = 10, temp = 1337;
  swap(a, b);
  printf("%d, %d, %d\n", a, b, temp);
  printf("%d", EOF);
  
  return 0;
}

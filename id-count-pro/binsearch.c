#include <string.h>

#include "binsearch.h"

int binsearch(char * word, char * list[], int list_length)
{
  int start = 0, end = list_length - 1, middle, c;
  
  while (start <= end)
    {
      middle = (start + end) / 2;

      if ((c = strcmp_e(word, list[middle])) == 0)
        {
          return middle;
        }
      else
        if (c < 0)
          end = middle - 1;
        else
          start = middle + 1;
    }
  
  return -1;            
}

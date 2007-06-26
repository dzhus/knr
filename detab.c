/**
 * K&R 1.20, 5.11
 * Expanding tabs ('\t') in standard input to spaces
 * Not sure whether it behaves as expected by K&R, though...
 */

#include <stdio.h>
#define DEFAULT_TABSIZE 8
/// Hackish :)
#define MAKE_TABSIZE                                            \
  tabsize = (col < argc) ? atoi(argv[col]) : DEFAULT_TABSIZE
  
int main (int argc, char *argv[])
{
  /// Currently filled symbols in the next tab column
  int t = 0, col = 1, tabsize = DEFAULT_TABSIZE;
  
  int i;
  char c;

  MAKE_TABSIZE;
  
  while (EOF != (c = getchar()))
    {
      if (t == tabsize)
        {
          t = 0;
          col++;
          MAKE_TABSIZE;
        }
      if (c == '\t')
        {
          for (i = 0; i < (tabsize - t); i++)
            putchar(' ');
          t = 0;
          col++;
          MAKE_TABSIZE;
        }
      else
        {
          putchar(c);
          if (c != '\n')
            t++;
          else
            {
              t = 0;
              col = 1;
              MAKE_TABSIZE;
            }
        }
    }
}

/**
 * K&R 5.13
 *
 * Simple version of `tail` program.
 *
 * `-n` command line option is respected.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alloc.h"
#define MAXLINE 1000
#define LINES 1000

static char *line_ptr[LINES];

int main(int argc, char *argv[])
{
  int getline(char [], int), total, tail;
  int readlines(void);
  void writelines(int, int);
    
  while (--argc && strcmp(*argv++, "-n"))
    ;
  tail = (tail = atoi(*argv)) ? tail : 10;

  total = readlines();
  tail = (total > tail) ? tail : total;
    
  if (total == -1)
    return 1;
/*   printf("total=%d, tail=%d", total, tail); */
  else if (total)
    writelines(total, tail);
  return 0;
}

int getline(char s[], int max)
{
  int c, i;
  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n')
    {
      s[i] = c;
      ++i;
    }
  s[i] = '\0';
  return i;
}

int readlines(void)
{
  char line[MAXLINE], *p;
  int len, nlines = 0;
  while ((len = getline(line, MAXLINE)) > 0)
    if (nlines >= LINES || (p = alloc(len)) == NULL)
      return -1;
    else
      {
        line[len-1] = '\0';
        strcpy(p, line);
        line_ptr[nlines++] = p;
    }
  return nlines;
}

void writelines(int total, int tail)
{
  do
    printf("%s\n", line_ptr[total - tail]);
  while (--tail);
}

  
    

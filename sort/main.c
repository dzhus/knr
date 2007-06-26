/**
 * K&R 5.14 5.15
 *
 * Simple `sort` program, sorting standard input.
 *
 * Possible options:
 * `-n`    numeric sort
 * `-r`    sort in reverse order
 * `-f`    case-insensitive sorting
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alloc.h"
#define MAXLINE 1000
#define LINES 1000
#define GREATER 1

static char *line_ptr[LINES];

int getline(char [], int);
int readlines(void);
void writelines(int);

void sort(void *v[], int size, int (*comp)(void *, void *), int reverse);
int numcmp(char *, char *);
int stricmp(char *, char *);

int main(int argc, char *argv[])
{
  int ignore_case = 0, reverse = 0, directory = 0;  
  int nlines, numeric = 0;
  char c;

  while (--argc && (*++argv)[0] == '-')
    while (c = *++argv[0])
      switch (c)
        {
        case 'n':
          numeric = 1;
          break;
        case 'r':
          reverse = 1;
          break;
        case 'f':
          ignore_case = 1;
          break;
        case 'd':
          /* not implemented */
          directory = 1;
          break;
        }
    
  if ((nlines = readlines()) >= 0)
    {
      sort((void *)line_ptr, nlines, (int (*)(void *, void *)) \
           (numeric ? numcmp : (ignore_case ? stricmp : strcmp)), \
           reverse);
      writelines(nlines);
    }
  else
    {
      printf("Too many rows to sort!\n");
      return -1;
    }

  return 0;
}

int numcmp(char *s1, char *s2)
{
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  else if (v1 > v2)
    return 1;
  else
    return 0;
}

/* not charset independent! */
int stricmp(char *a, char *b)
{
  for ( ; tolower(*a) == tolower(*b); a++, b++)
    {
      if (*a == '\0' || *b == '\0')
        return 0;
    }
  
  return tolower(*a) - tolower(*b);
}

void swap(void *v[], int a, int b)
{
  void *temp;
  
  temp = v[a];
  v[a] = v[b];
  v[b] = temp;
}

void sort(void *v[], int size, int (*comp)(void *, void *), int reverse)
{
  int swaps = 1, distance, i;

  for (distance = size - 1; distance > 0; distance--)
    {
      do
        {
          swaps = 0;
          for (i = 0; (i + distance) <= (size - 1); i++)
            {
              if (!reverse)
                {
                  if ((*comp)(v[i], v[i + distance]) > 0)
                    {
                      swaps = 1;
                      swap((void *)v, i, i + distance);
                    }
                }
              /// @internal We cannot regroup if's as it will cause bugs when two compared
              /// elements are equal.
              else if ((*comp)(v[i], v[i + distance]) < 0)
                {
                  swaps = 1;
                  swap((void *)v, i, i + distance);
                }
            }
        }
      while (swaps);
    }
}

int getline(char s[], int max)
{
  int c, i;
  for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    s[i] = c;
  if (c == '\n')
    {
      s[i++] = c;
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

void writelines(int total)
{
  int i = 0;
  while (i < total)
    printf("%s\n", line_ptr[i++]);
}

  
    

#include <stdio.h>

#define BUFSIZE 100

static char buf[BUFSIZE];
static int bufp = 0;

int getch(void)
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c)
{
  if (bufp >= BUFSIZE)
    printf("Ungetch: too many characters.\n");
  else buf[bufp++] = c;
}


/*
  Proper handling of preprocessor directives, underscores and strings.
  Comments handling is NOT implemented; thus, words in comments are
  not ignored!
  
  Returns EOF, if stream end reached; first char of word, if word
  occured; char, if non-printable character encountered.
*/
char getword(char * w, int lim)
{
  char c;

  *w = '\0';
  
  while (isspace(c = getch()))
    if (c == '\n') 
      {
        return c;
      }
  
  if (c == '\"')
    while ((c = getch()) != '\"')
      if (c == EOF)
        return c;
    
  if (!(isalpha(c) || c == '_' || c == '#'))
    {
      return c;
    }
  else
    *w++ = c;

  for ( ; --lim > 0; w++)
    if (!(isalnum(*w = getch()) || *w == '_' ||  *w == '#' || *w == '\''))
      {
        ungetch(*w);
        break;
      }

  *w = '\0';
  
  return c;
}

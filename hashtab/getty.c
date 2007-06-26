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
  Proper handling of preprocessor directives and underscore.
  Proper comments and string handling is NOT implemented!

  Word is [#_A-z0-9][_A-z0-9'].
  
  Additional 'defn' argument switches word recognition rule so that
  'word' lexem ends at the *end of line*. Works only for `#define word
  <this_part>` and `#undef <this_part>`

  @return EOF, if stream end reached; char, if word
  occured; non-printable character, if encountered.

  @todo Strings handling
  @todo Comments handling

  @note This function may return space character, too.
*/
char getword(char * w, int lim, int defn)
{
  char c;
/*   printf("Entered, defn = %d\n", defn); */
  
  *w = '\0';

  c = getch();
  
  if (!(isalnum(c) || c == '_' || c == '#'))
    return c;
  else
    *w++ = c;

  for ( ; --lim > 0; w++)
    if (!defn)
      {
        if (!(isalnum(*w = getch()) || *w == '_' || *w == '\''))
          {
            ungetch(*w);
            *w = '\0';
            break;
          }
      }
    else
      if (*w == '\n' || *w == EOF)
        {
          ungetch(*w);
          *--w = '\0';
          break;
        }


          
 /*  printf("Returning %c, word %s\n", c, w); */

  return c;
}

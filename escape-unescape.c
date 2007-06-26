/**
 * K&R 3.2
 */

#include <stdio.h>
#define BUF 100

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main ()
{
  char s[BUF], t[BUF], c;
  int i = 0;
  while ((c = getchar()) != EOF)
    s[i++] = c;
  s[i] = '\0';
  escape(s, t);
  printf("%s to %s\n", s, t);
  printf("%s back to %s", t, s);
}

void escape(char s[], char t[])
{
  int i = 0, j = 0;
  while (s[i] != '\0')
    {
      switch (s[i])
        {
        case '\t':
          t[j++] = '\\';
          t[j++] = 't';
          break;
        case '\n':
          t[j++] = '\\';
          t[j++] = 'n';
          break;
        case '\'':
          t[j++] = '\\';
          t[j++] = '\'';
          break;
        case '\"':
          t[j++] = '\\';
          t[j++] = '"';
          break;
        case '\\':
          t[j++] = '\\';
          t[j++] = '\\';
          break;
        default:
          t[j++] = s[i];
          break;
        }
      i++;
    }
  t[j] = '\0';
}

void unescape(char s[], char t[])
{
  int i = 0, j = 0;
  while (s[i] != '\0')
    {
      switch (s[i])
        {
        case '\\':
          switch (s[i++])
            {
            case 't':
              t[j++] = '\t';
              break;
            case 'n':
              t[j++] = '\n';
              break;
            case '\'':
              t[j++] = '\'';
              break;
            case '\"':
              t[j++] = '\"';
              break;
            }
          break;
        default:
          t[j++] = s[i++];
          break;
        }
    }
}

          
              

/**
 * K&R 5.3, 5.4, 5.5
 */

#include <stdio.h>
#define L 25
#define debug(expr) printf(#expr " = %d\n", expr)

void strcat2(char *s, char *t)
{
  s += strlen(s);
  while (*s++ = *t++)
    ;
}

void strncat2(char *s, char *t, int n)
{
  s += strlen(s);
  while (n-- > 0 && (*s++ = *t++))
    ;
}

int strncmp2(char *s, char *t, int n)
{
  /* @attention Using 'while' will fail on strncmp("love", "lobe") */
  for ( ; n-- && *s == *t; s++, t++)
    if (*s == '\0')
      return 0;
  return *s - *t;
}

void strncpy2(char *s, char *t, int n)
{
  while (n-- && (*s++ = *t++))
    ;
}

int strend2(char *s, char *t)
{
  if (strlen(t) > strlen(s))
    return 0;
  s += (strlen(s) - strlen(t));
  
  /* @attention Using 'while' here is wrong as it'll fail on strend("belove", "lobe") */
  for ( ; *s == *t; s++, t++)
    if (*s == '\0')
      return 1;
  return 0;
}

int main(void)
{
  char s[L] = "national";
  char p[L] = "";
  char *t = "ism";
  char *q = "isqw";
  
  strcat2(s, t);
  strncat2(p, s, L);
  strcat2(p, q);
  
  printf("%s, %s\n", s, p);
  return 0;
}



  

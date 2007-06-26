#include <string.h>
#include <stdlib.h>

#include "compare.h"

/**
    Numerical string comparison.

    Thus, `numcmp("532", "25") == 1`, `numcmp("1", "100") == -1`.
*/
char numcmp(char * s1, char * s2)
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

/* Case-ignorant strcmp */
char stricmp(char * a, char * b)
{
  return strcmp_e(a, b);
}

/**
   Preprocessor directive-aware strcmp.

   Common `strcmp` would choke on `strcmp("#def", "abra")`. This
   version works in a way that `strcmp("#define", "define") == 0`!
*/
char strcmp_e(char * cs, char * ct)
{
  if (cs[0] == '#')
    if (ct[0] == '#')
      return strcmp_e(++cs, ++ct);
    else
      return strcmp_e(++cs, ct);
  else
    if (ct[0] == '#')
      return strcmp_e(cs, ++ct);
    else
      return strcmp(cs, ct);
}

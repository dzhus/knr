/**
 * K&R 4.2
 */
#include <stdio.h>
#include <ctype.h>

int main(void)
{
  double atof(char []);
  printf("%f", atof("2133E+2"));
  return 0;
}

double atof(char *s)
{
  double val, power, e_val, e_sign = 1;
  int sign;

  while (isspace(*s++))
    ;
  sign = (*s == '-') ? -1 : 1;
  if (*s == '+' || *s == '-')
    s++;
  for (val = 0.0; isdigit(*s); s++)
    val = 10.0 * val + (*s - '0');
  if (*s == '.')
    s++;
  for (power = 1.0; isdigit(*s); s++) 
    {
      val = 10.0 * val + (*s - '0');
      power *= 10;
    }
  if ((*s == 'e' || *s == 'E') && (isdigit(*(s+1)) || *(s+1) == '+' || *(s+1) == '-'))
    {
      s++;

      if (*s == '+')
        {
          e_sign = 1;
          s++;
        }
      else if (*s == '-')
        {
          e_sign = -1;
          s++;
        }
      
      for (e_val = 0.0; isdigit(*s); s++)
        e_val = 10.0 * e_val  + (*s - '0');

      for (e_val *= e_sign; e_val != 0; e_val -= e_sign)
        if (e_sign == -1) 
          power *= 10; 
        else
          power /= 10; 
    }
  
  return sign * val / power;
}

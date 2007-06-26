#include <stdio.h>

#define MAXVAL 100

int sp = 0;
static double val[MAXVAL];

void push(double f)
{
  if (sp < MAXVAL)
    val [sp++] = f;
  else
    printf("Error: stack full, can't push %g.\n", f);
}

double pop(void)
{
  if (sp > 0)
    return val[--sp];
  else 
    {
      printf("Error: stack empty.\n");
      return 0.0;
    }
}

double gettopnopop(void)
/* t3h як-цуп-цоп */
{
  if (sp > 0)
    return val[sp];
  else
    {
      printf("Error: stack empty.\n");
      return 0.0;
    }
}

void swap(void)
{
  double op1, op2;
  
  if (sp > 1)
    {
      op2 = pop();
      op1 = pop();
      push(op2);
      push(op1);
    }
  else
    {
      printf("Error: stack empty.\n");
    }
}

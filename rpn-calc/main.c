#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
  
int main(void)
{
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF)
    {
      switch(type)
        {
        case NUMBER:
          push(atof(s));
          break;
        case '+':
          push(pop() + pop());
          break;
        case '*':
          push(pop() * pop());
          break;
        case '-':
          push(0 - pop() + pop());
          break;
        case '/':
          op2 = pop();
          if (op2 != 0.0)
            push(pop() / op2);
          else
            printf("Error: division by zero.\n");
          break;
        case '%':
          op2 = pop();
          if (op2 != 0.0)
            push((int)pop() % (int)op2);
          else
            printf("Error: division by zero.\n");
          break;
        case '\n':
          printf("\t%.8g\n", pop());
          break;
        default:
          printf("Error: unknown token %s.\n", s);
          break;
        }
     }
  return 0;
}

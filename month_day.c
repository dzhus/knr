/**
 * K&R 5.9
 */

static char daytab[2][13] = 
  {
    {
      0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    }
    ,
    {
      0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    }
  };


int day_of_year(int year, int month, int day)
{
  int i, leap;

  leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

  for (i = 1; i < month; i++)
    day += *(*(daytab+leap)+i);
  return day;
}

int main(void)
{
  printf("%d", day_of_year(1989, 3, 19));
  return 0;
}

  

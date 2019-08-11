#include <stdio.h>

int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

void go()
{
  int total_days = 1; //starts on monday
  total_days += 365; //puts us at Jan 1, 1901
  int year = 1901;
  int count = 0;
  int curr_month;

  while(year <= 2000)
  {
    for(curr_month = 0; curr_month < 12; curr_month++)
    {
      if(total_days % 7 == 0)
      {
        count++;
      }
      total_days += days[curr_month];
      if(curr_month == 1)
      {
        if(year % 4 == 0 && !(year % 100 == 0))
        {
          total_days++;
        }
        if(year % 100 == 0 && year % 400 == 0)
        {
          total_days++;
        }
      }
    }
    year++;
  }

  printf("Answer: %d\n", count);
}

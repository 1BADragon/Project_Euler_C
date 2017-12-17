#include <stdio.h>

void go()
{
  int i, total = 0;
  for(i = 0; i < 1000; i++)
  {
    if(i % 3 == 0)
    {
      total += i;
    }
    else if(i % 5 == 0)
    {
      total += i;
    }
  }
  printf("Total: %d\n", total);
}

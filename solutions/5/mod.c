#include <stdio.h>

void go()
{
  int i=0,j;
  int good = 0;
  while(1)
  {
    i++;
    good = 1;
    for(j = 1; j <= 20; j++)
    {
      if(i % j != 0)
      {
        good = 0;
      }
    }
    if(good)
    {
      break;
    }
  }
  printf("Answer: %d\n", i);
}

#include <stdio.h>
#include <utils.h>

void go()
{
  int i,j,prod;
  int max = 0;
  for(i = 999; i >= 100; i--)
  {
    for(j = i; j >=100; j--)
    {
      prod = i * j;
      if(is_palandrome(prod) && prod > max)
      {
        max = prod;
      }
    }
  }
  printf("Total: %d\n", max);
}

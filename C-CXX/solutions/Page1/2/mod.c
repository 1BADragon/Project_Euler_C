#include <stdio.h>
#include <inttypes.h>

void go()
{
  //2 will be counted before hand
  uint64_t x1=1, x2=2, x3=0, sum=2;
  while(x3 <= 4000000)
  {
    x3 = x1 + x2;
    //printf("x3: %ld\n", x3);
    if(x3 % 2 == 0)
    {
      sum += x3;
    }
    x1 = x2;
    x2 = x3;
  }
  printf("Total: %ld\n", sum);
}

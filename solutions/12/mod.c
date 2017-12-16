#include <stdio.h>
#include <utils.h>
#include <inttypes.h>

void go()
{
  int64_t num = 0;
  int64_t i = 0;
  while(1)
  {
    i++;
    num += i;
    if(factors_int64(num, NULL) > 500)
    {
      break;
    }
  }
  printf("Answer: %ld\n", num);
}

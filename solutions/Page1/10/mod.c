#include <stdio.h>
#include <utils.h>
#include <inttypes.h>

void go()
{
  int64_t sum = 0;
  int64_t i;
  for(i = 2; i < 2000000; i++)
  {
    if(is_prime_int64(i))
    {
      sum += i;
    }
  }

  printf("Answer: %ld\n", sum);
}

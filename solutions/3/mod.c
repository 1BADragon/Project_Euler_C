#include <stdio.h>
#include <inttypes.h>
#include <utils.h>

void go()
{
  int64_t target = 600851475143;
  int64_t i, max;
  for(i = 2; i*i <= target; i++)
  {
    if(target % i == 0)
    {
      if(is_prime_int64(i))
      {
        max = i;
      }
    }
  }
  printf("Max: %ld\n", max);
}

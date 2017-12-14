#include <utils.h>
#include <math.h>


int is_prime_int64(int64_t val)
{
  int64_t half = val / 2;
  int64_t i;
  for(i = 2; i < half; i++)
  {
      if(val % i == 0)
      {
        return 0;
      }
  }
  return 1;
}

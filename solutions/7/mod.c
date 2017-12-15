#include <stdio.h>
#include <inttypes.h>
#include <utils.h>

void go()
{
    uint64_t i = 1;
    int count = 0;
    while(1)
    {
      i += 1;
      if(is_prime_int64(i))
      {
        count++;
      }
      if(count == 10001)
        break;
    }

    printf("Anser: %ld\n", i);
}

#include <stdio.h>
#include <inttypes.h>

void go()
{
  uint64_t sumsquar=0, squarsum=0;
  int i;
  for(i = 1; i <= 100; i++)
  {
    sumsquar += i*i;
    squarsum += i;
  }

  squarsum = squarsum * squarsum;

  printf("Answer: %ld\n", squarsum - sumsquar);

}

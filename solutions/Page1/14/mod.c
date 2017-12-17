#include <stdio.h>
#include <inttypes.h>


void go()
{
  uint64_t max = 0;
  uint64_t temp,start,count,number;
  for(start = 1; start < 1000000; start++)
  {
    count = 1;
    temp = start;
    while(temp != 1)
    {
      count++;
      if(temp % 2 == 0) //even
      {
        temp = temp / 2;
      }
      else //odd
      {
        temp = 3*temp + 1;
      }
    }
    if(count > max)
    {
      number = start;
      max = count;
    }
  }

  printf("Answer: %ld\n", number);
}

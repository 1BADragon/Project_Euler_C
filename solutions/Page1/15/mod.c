#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#define SIZE 20

void go()
{
  uint64_t *l = calloc(SIZE+1, sizeof(uint64_t));
  int i,j;
  for(i = 0; i <= SIZE; i++)
  {
    l[i] = 1;
  }
  for(i = 1; i <= SIZE; i++)
  {
    for(j = 1; j < i; j++)
    {
      l[j] = l[j] + l[j-1];
    }
    l[i] = 2 * l[i - 1];
  }

  printf("Answer: %ld\n", l[SIZE]);
}

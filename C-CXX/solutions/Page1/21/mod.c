#include <stdio.h>
#include <inttypes.h>
#include "utils.h"


void go()
{
  int i;
  int64_t sum = 0;
  int64_t *factors;
  int num_factors;
  int64_t factor_sum, bsum;
  for(i = 1; i < 10000; i++)
  {
    factors = NULL;
    num_factors = factors_int64(i, &factors);
    //print_int64_array(factors, num_factors);
    factor_sum = sum_int64(factors, num_factors-1);
    //printf("factor_sum %ld\n", factor_sum);
    free(factors);
    factors = NULL;
    num_factors = factors_int64(factor_sum, &factors);
    //print_int64_array(factors, num_factors);
    bsum = sum_int64(factors, num_factors-1);
    //printf("bsum %ld\n", bsum);
    if(i == bsum && i != factor_sum)
    {
      sum += i;
    }
  }
  printf("Answer: %ld\n", sum);
}

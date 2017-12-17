#include <stdio.h>
#include <inttypes.h>
#include <utils.h>
#include <gmp.h>
#include "value.h"

void go()
{
  mpz_t temp, total;
  mpz_init(temp);
  mpz_init(total);
  int i, num_size;
  char *number;

  for(i = 0; i < 100; i++)
  {
    mpz_set_str(temp, values[i], 10);
    mpz_add(total, total, temp);
  }
  num_size = mpz_sizeinbase(total, 10);
  number = calloc(num_size+1, sizeof(char));
  gmp_sprintf(number, "%Zd", total);


  printf("Answer: %10.10s\n", number);

  mpz_clear(temp);
  mpz_clear(total);
  free(number);
}

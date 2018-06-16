#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void go()
{
  mpz_t total;
  mpz_init(total);
  mpz_fac_ui(total, 100);

  char *digits;
  size_t num_digits = mpz_sizeinbase(total, 10);
  digits = calloc(num_digits+1, sizeof(char));
  gmp_snprintf(digits, num_digits+1, "%Zd", total);
  mpz_t sum;
  mpz_init(sum);
  size_t i;
  for(i = 0; i < num_digits-1; i++)
  {
    //printf("%d\n", digits[i] - '0');
    mpz_add_ui(sum, sum, digits[i] - '0');
  }

  gmp_printf("Answer: %Zd\n", sum);
}

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

void go()
{
  mpz_t number,answer;
  mpz_init(number);
  mpz_init(answer);
  mpz_ui_pow_ui(number, 2, 1000);
  int size = mpz_sizeinbase(number, 10);
  char *digits = calloc(size+1, sizeof(char));
  gmp_sprintf(digits, "%Zd", number);
  int i;
  for(i = 0; i < size; i++)
  {
      mpz_add_ui(answer, answer, (unsigned long int)(digits[i] - '0'));
  }
  gmp_printf("Answer: %Zd\n", answer);
}

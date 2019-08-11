#include <stdio.h>
#include <gmp.h>
#include "number.h"

void max(mpz_t v1, mpz_t v2, mpz_t ret)
{
  switch(mpz_cmp(v1, v2))
  {
    case 1: //v1 > v2
      mpz_set(ret, v1);
      break;
    case 0: //v1 == v2
      mpz_set(ret, v1);
      break;
    case -1: //v1 < v2
      mpz_set(ret, v2);
      break;
  }
}

void go()
{
  mpz_t numbers[15][15];
  mpz_t temp;
  mpz_init(temp);
  int i,j;
  for(i = 0; i < 15; i++)
  {
    for(j = 0; j < 15; j++)
    {
      mpz_init(numbers[i][j]);
      mpz_set_si(numbers[i][j], values[i][j]);
      //gmp_printf("%Zd ", numbers[i][j]);
    }
    //printf("\n");
  }

  for(i = 14; i > 0; i--)
  {
    for(j = 0; j < i; j++)
    {
      max(numbers[i][j], numbers[i][j+1], temp);
      //gmp_printf("i:%d j:%d o1:%Zd 02:%Zd temp:%Zd\n", i, j, numbers[i][j], numbers[i][j+1], temp);
      mpz_add(numbers[i-1][j], numbers[i-1][j], temp);
    }
  }

  gmp_printf("Answer: %Zd\n", numbers[0][0]);
  return;
}

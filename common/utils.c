#include <utils.h>

int is_prime_int64(int64_t val)
{
  int64_t i;
  if(val == 2)
    return 1;
  for(i = 2; i*i <= val; i++)
  {
      if(val % i == 0)
      {
        return 0;
      }
  }
  return 1;
}

int is_palandrome(int val)
{
  int num_digits = log10(val) + 1;
  char *digits = (char *)calloc(num_digits+1, sizeof(char));

  if(snprintf(digits, num_digits+1, "%d", val) != num_digits)
  {
    printf("Palandrome Error\nnum_digits: %d\nInput: %d\nOutput: %s\n", num_digits, val, digits);
    exit(1);
  }
  char *x1=digits, *x2=digits+(num_digits-1);
  int i;
  for(i = 0; i < num_digits/2; i++)
  {
    if(*x1 != *x2)
      return 0;
    x1++;
    x2--;
  }

  return 1;
}

#include <utils.h>

int64_t sum_int64(int64_t *vals, int n)
{
  int64_t total = 0;
  int i;
  for(i = 0; i < n; i++)
  {
    total += vals[i];
  }
  return total;
}

int factors_int64(int64_t val, int64_t **factors)
{
  if(val == 0)
  {
    return 0;
  }
  if(factors != NULL && *factors != NULL)
    return -1;
  int count = 0;
  int size = 2;
  if(factors != NULL)
    *factors = calloc(size, sizeof(int64_t));
  int i;
  for(i = 1; i*i < val; i++)
  {
    if(val % i == 0)
    {
      if(factors != NULL)
      {
        if(count >= size)
        {
          *factors = realloc(*factors, (size*2) * sizeof(int64_t));
          if(*factors == NULL)
            return -1;
          size *= 2;
        }
        (*factors)[count] = i;
        (*factors)[count+1] = val / i;
      }
      count += 2;
    }
  }
  if(i*i == val)
  {
    if(factors != NULL)
    {
      if(count >= size)
      {
        *factors = realloc(*factors, (size + 1) * sizeof(int64_t));
      }
      (*factors)[count] = i;
    }
    count++;
  }
  if(factors != NULL)
  {
    qsort((void *)*factors, count, sizeof(int64_t), int64_cmp);
  }
  return count;
}

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

void print_int64_array(int64_t *vals, int n)
{
  int i;
  for(i = 0; i < n; i++)
  {
    printf("%ld ", vals[i]);
  }
  printf("\n");
}

int int64_cmp(const void *v1, const void *v2)
{
  const int64_t *x1, *x2;
  x1 = v1;
  x2 = v2;
  if(*x1 < *x2)
    return -1;
  else if(*x1 == *x2)
    return 0;
  else
    return 1;
}

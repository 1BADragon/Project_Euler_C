#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <gmp.h>
#include <errno.h>
#include <utils.h>

int cmp_func(const void *v1, const void *v2)
{
    const char *x1 = *(const char**)v1;
    const char *x2 = *(const char**)v2;
    return strcmp(x1, x2);
}

void go()
{
  mpz_t sum;
  mpz_init(sum);
  char **names = NULL;
  FILE *fin = fopen("../solutions/Page1/22/p022_names.txt", "r");
  if(fin == NULL)
  {
    perror("Cannot open file:");
    exit(1);
  }

  size_t num_names = parse_cvs_file(fin, &names, ',');

  fclose(fin);
  size_t i,j;
  qsort(names, num_names, sizeof(char *), cmp_func);

  mpz_t total;
  mpz_init(total);
  unsigned long temp;

  for(i = 0; i < num_names; i++)
  {
      temp = 0;
      for(j = 1; j < strlen(names[i])-1; j++)
      {
          temp += ((names[i][j]-'A')+1);
      }
      mpz_add_ui(total, total, temp*(i+1));
  }
  gmp_printf("Answer %Zd\n", total);
}

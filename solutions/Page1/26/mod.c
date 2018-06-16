#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <gmp.h>

void go()
{
    mpf_t value;
    mpz_t num, dem;
    mpf_init2(value, 100000);

    mpz_init_set_ui(num, 1);
    mpz_init(dem);

    size_t max_rep_value = 0;
    size_t answer = 0;

    for(int i = 2; i < 1000; ++i)
    {
        mpf_set_ui(value, 1);
        mpf_div_ui(value, value, i);
        gmp_printf("%.*Ff\n", 250, value);
    }

    gmp_printf("Answer: %zd with %zd\n", max_rep_value, answer);
}

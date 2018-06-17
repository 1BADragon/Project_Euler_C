#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

void formula(mpz_t a, mpz_t b, mpz_t n, mpz_t solution)
{
    mpz_t temp;
    mpz_init(temp);

    mpz_pow_ui(solution, n, 2);
    mpz_mul(temp, a, n);
    mpz_add(solution, solution, temp);
    mpz_add(solution, solution, b);

    mpz_clear(temp);
}

int is_prime(mpz_t n)
{
    mpz_t i, sqrt_n, mod_val;
    mpz_init(i);
    mpz_init(sqrt_n);
    mpz_init(mod_val);

    int ret_val = 1;

    for(mpz_set_ui(i, 2); mpz_cmp(i, sqrt_n) <= 0; mpz_add_ui(i, i, 1))
    {
        mpz_mod(mod_val, n, i);
        if(mpz_cmp(mod_val, 0) == 0)
        {
            ret_val = 0;
            break;
        }
    }

    mpz_clear(mod_val);
    mpz_clear(sqrt_n);
    mpz_clear(i);
    return ret_val;
}

void go()
{
    mpz_t value;
    mpz_init_set_ui(value, 20);
    printf("%d\n", is_prime(value));
}

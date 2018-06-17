#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>

//probably dont need gmp but who cares...

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
    mpz_init_set_ui(i, 2);
    mpz_init(sqrt_n);
    mpz_init(mod_val);
    int ret_val = 1;
    mpz_sqrt(sqrt_n, n);
    mpz_add_ui(sqrt_n, sqrt_n, 1);
    while (mpz_cmp(i, sqrt_n) <= 0)
    {        
        mpz_mod(mod_val, n, i);
        if(mpz_cmp_ui(mod_val, 0) == 0)
        {
            ret_val = 0;
            break;
        }
        mpz_add_ui(i, i, 1);
    }
    mpz_clear(mod_val);
    mpz_clear(sqrt_n);
    mpz_clear(i);
    return ret_val;
}

void go()
{
    mpz_t a,b,n,sol,count,answer,max_count;
    mpz_init(a);
    mpz_init(b);
    mpz_init(n);
    mpz_init(sol);
    mpz_init_set_ui(max_count, 0);
    mpz_init(answer);
    mpz_init(count);



    for(mpz_set_si(a, -999); mpz_cmp_ui(a, 999) < 0; mpz_add_ui(a, a, 1))
    {
        for(mpz_set_si(b, -1000); mpz_cmp_ui(b, 1000) <= 0; mpz_add_ui(b, b, 1))
        {
            mpz_set_ui(count, 0);
            mpz_set_ui(n, 0);

            while(1)
            {
                formula(a, b, n, sol);
                mpz_abs(sol, sol);
                if(is_prime(sol))
                {
                    mpz_add_ui(count, count, 1);
                }
                else
                {
                    break;
                }
                mpz_add_ui(n, n, 1);
            }

            if(mpz_cmp(count, max_count) > 0)
            {
                mpz_set(max_count, count);
                mpz_mul(answer, a, b);
            }

        }
    }

    gmp_printf("Answer: %Zd(%Zd)\n", answer, max_count);

    mpz_clear(a);
    mpz_clear(b);
    mpz_clear(n);
    mpz_clear(sol);
    mpz_clear(count);
    mpz_clear(answer);
}

#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

size_t max_digits = 1000;

void go()
{
    mpz_t f1,f2,fn, term;
    mpz_init_set_ui(f1, 1);
    mpz_init_set_ui(f2, 2);
    mpz_init(fn);
    mpz_init_set_ui(term, 3);

    while(1)
    {
        mpz_add(fn, f1, f2);
        mpz_add_ui(term, term , 1);
        if(mpz_sizeinbase(fn, 10) >= 1000)
            break;
        mpz_set(f2, f1);
        mpz_set(f1, fn);

    }

    gmp_printf("Answer: %Zd\n", term);
}

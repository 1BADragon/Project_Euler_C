#include <stdio.h>
#include <utils.h>


bool is_abundant(int64_t val)
{
    int64_t *factors=NULL;
    int factor_count = factors_int64(val, &factors);

    return val < sum_int64(factors, factor_count-1);  
}

void go()
{
    const int64_t max_val = 28123;
    int64_t total = 0;
    int64_t i,j;
    bool valid;;

    for(i = 1; i <= max_val; i++)
    {
        valid = TRUE;
        //printf("i: %ld\n", i);
        //printf("Testing to: %ld\n", (i/2)+1);
        for(j = 0; j <= (i/2)+1; j++)
        {
            //printf("Testing %ld+%ld\n", j, (i-j));
            bool i_abundent = is_abundant(j);
            bool i_j_abundent = is_abundant(i-j);
            //printf("j: %d, i-j: %d\n", i_abundent, i_j_abundent);
            if(i_abundent && i_j_abundent)
            {
                valid = FALSE;
                break;
            }
        }
        if(valid)
        {
            //printf("valid: %ld\n", i);
            total += i;
        }
    }

    printf("Answer: %ld\n", total);
}
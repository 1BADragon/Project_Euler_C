#include <stdio.h>
#include <utils.h>

int64_t numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int64_t n_numbers = 10;

int64_t fact(int64_t val)
{
    if(val == 0 || val == 1)
        return 1;
    return fact(val-1) * val;
}

int64_t int64_ceil(double val)
{
    if((val - (int64_t)val) == 0)
    {
        return val;
    }
    return (int64_t)val+1;
}

void perm(int64_t *numbers, int64_t *ret, int64_t ret_size, int64_t curr, int64_t perm_c)
{
    if(ret_size == 0)
    {
        return;
    }
    int64_t index = int64_ceil(((double)perm_c/(double)fact(ret_size))*ret_size)-1;
    printf("index: %ld, retsize: %ld\n", index, ret_size);
    int64_t val = numbers[index];
    ret[curr] = val;

    int64_t *ret_nums = calloc(ret_size-1, sizeof(int64_t));

    int i = 0;
    int j = 0;
    for(i = 0; i < ret_size; i++)
    {
        if(numbers[i] == val)
        {
            continue;
        }
        ret_nums[j] = numbers[i];
        j++;
    }

    perm(ret_nums, ret+1, ret_size - 1, 0, perm_c);
    free(ret_nums);
}

void go()
{
    int64_t *ret = calloc(3, sizeof(int64_t));
    int64_t numbers[] = {0,1,2};
    perm(numbers, ret, 3, 0, 4);
    printf("Answer: ");
    print_int64_array(ret, 3);
}


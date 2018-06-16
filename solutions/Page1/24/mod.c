#include <stdio.h>
#include <stdlib.h>
#include <utils.h>

int64_t n_numbers = 10;
int64_t perm = 1000000;

int64_t fact(int64_t num)
{
    if(num < 0)
        return -1;
    if(num == 0)
        return 1;
    return num * fact(num-1);
}

int64_t *remove_item(int64_t *list, size_t size, size_t index)
{
    int64_t *ret = calloc(size-1, sizeof(int64_t));
    size_t ret_index = 0;
    for(size_t i = 0; i < size; ++i)
    {
        if(i == index)
            continue;
        ret[ret_index] = list[i];
        ++ret_index;
    }
    free(list);
    return ret;
}

void go()
{
    int64_t answer[10];
    size_t answer_index = 0;
    memset(answer, 0, sizeof(answer));
    int64_t remain = perm - 1;
    int64_t N = n_numbers;
    int64_t numbers_left = 10;
    int64_t *numbers = calloc(n_numbers, sizeof(uint64_t));
    int64_t *temp;

    for(int i = 0; i < n_numbers; ++i)
    {
        numbers[i] = i;
    }

    for(int i = 1; i < n_numbers; i++)
    {
        int j = remain / fact(N - i);
        remain = remain % fact(N - i);
        answer[answer_index] = numbers[j];
        ++answer_index;
        temp = remove_item(numbers, numbers_left, j);
        free(numbers);
        numbers = temp;
        numbers_left--;
        if(remain == 0)
            break;
    }

    for(int i = 0; i < numbers_left; ++i)
    {
        answer[answer_index] = numbers[i];
        ++answer_index;
    }

    printf("Answer: ");
    print_int64_array(answer, 10);
    free(numbers);
}


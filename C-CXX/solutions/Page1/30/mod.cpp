#include <iostream>
#include <cmath>

extern "C" {
    void go();
}

static uint64_t pow5sum(uint64_t);

void go()
{
    uint64_t current_number = 2;
    uint64_t sum = 0;
    uint64_t temp_val;

    while(true)
    {
        temp_val = pow5sum(current_number);

        if(temp_val == current_number)
        {
            sum += current_number;
        }

        if(current_number == 355000)
        {
            break;
        }

        current_number++;
    }
    std::cout << "Answer: " << sum << std::endl;
    return;
}

static uint64_t pow5sum(uint64_t val)
{
    uint64_t sum = 0;

    while(val > 0)
    {
        sum += pow(val % 10, 5);
        val = val / 10;
    }
    return sum;
}


#include <set>
#include <integer.h>

extern "C" {
    void go();
}

void go()
{
    unsigned long range = 100;
    std::set<Integer> values;
    for(unsigned long a = 2; a <= range; ++a)
    {
        for(unsigned long b = 2; b <= range; ++b)
        {
            values.insert(Integer::pow(a,b));
        }
    }

    std::cout << "Answer: " << values.size() << std::endl;
}

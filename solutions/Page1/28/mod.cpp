#include <iostream>
#include <integer.h>
#include <vector>
#include <utils.h>

extern "C" {
    void go();
}


void go()
{
    Integer total = 1;
    Integer size = 1001;
    Integer root, top_right, top_left, bottem_left, bottem_right;
    Integer total_rounds = size/2 + 1;
    for(Integer i = 1; i < total_rounds; ++i)
    {
        root = (i * 2) + 1;
        top_right = root * root;
        total += top_right;
        top_left = top_right - (i * 2);
        total += top_left;
        bottem_left = top_left - (i * 2);
        total += bottem_left;
        bottem_right = bottem_left - (i * 2);
        total += bottem_right;
    }

    std::cout << "Answer: " << total << std::endl;
}

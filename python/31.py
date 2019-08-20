#!/usr/bin/env python3

import sys

coins = [1,2,5,10,20,50,100,200]

def get_ways(val, current):
    if val <= 0:
        return 1
    else:
        s = 0
        for c in coins:
            if val >= c and c >= current:
                s += get_ways(val - c, c)
        return s

print(get_ways(int(sys.argv[1]), 0))



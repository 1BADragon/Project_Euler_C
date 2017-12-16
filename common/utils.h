#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>

int is_prime_int64(int64_t val);
int is_palandrome(int val);
int factors_int64(int64_t val, int64_t **factors);

#endif

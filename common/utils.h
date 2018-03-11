#ifndef UTILS_H
#define UTILS_H
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>
#include <math.h>
#include <stdio.h>

typedef int bool;
#undef TRUE
#define TRUE 1
#undef FALSE
#define FALSE 0

int is_prime_int64(int64_t val);
int is_palandrome(int val);
int factors_int64(int64_t val, int64_t **factors);
int64_t sum_int64(int64_t *vals, int n);
void print_int64_array(int64_t *vals, int n);
void sort_int64_array(int64_t *vals, int n);
int parse_cvs_file(FILE *fin, char ***array_ptr, char delim);

int int64_cmp(const void *v1, const void *v2);

#endif

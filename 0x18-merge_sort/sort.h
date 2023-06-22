#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *left, int *right, size_t left_size, size_t right_size);
void merge_sort_recursive(int *array, size_t size);

#endif /* SORT_H */

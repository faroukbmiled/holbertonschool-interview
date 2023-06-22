#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void split(int *arr, int first, int last, int *sorted_arr);
void merge(int *arr, int start, int mid, int end, int *copy);

#endif /* SORT_H */

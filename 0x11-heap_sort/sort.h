#ifndef MAIN_h
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void print_array(const int *array, size_t size);
void heap_sort(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);

#endif

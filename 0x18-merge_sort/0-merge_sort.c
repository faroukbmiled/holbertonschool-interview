#include "sort.h"

/**
 *merge_sort - Sorts an array of integers in ascending
 *@array: Tarray
 *@size: Number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
if (array == NULL || size < 2)
return;

merge_sort_recursive(array, size);
}

/**
 *merge - merges two arrays into one sorted array.
 *@array: main array
 *@left: left array
 *@right: right array
 *@left_size: Size of the left array
 *@right_size: Size of the right array
 */
void merge(int *array, int *left, int *right,
size_t left_size, size_t right_size)
{
size_t i = 0, j = 0, k = 0;
int *tmp = malloc((left_size + right_size) * sizeof(int));

if (tmp == NULL)
return;
printf("Merging...\n[left]: ");
print_array(left, left_size);
printf("[right]: ");
print_array(right, right_size);
while (i < left_size && j < right_size)
{
if (left[i] <= right[j])
{
tmp[k] = left[i];
i++;
}
else
{
tmp[k] = right[j];
j++;
}
k++;
}
while (i < left_size)
{
tmp[k] = left[i];
i++;
k++;
}
while (j < right_size)
{
tmp[k] = right[j];
j++;
k++;
}
for (i = 0; i < left_size + right_size; i++)
array[i] = tmp[i];
printf("[Done]: ");
print_array(array, left_size + right_size);
free(tmp);
}

/**
 *merge_sort_recursive - Recursively divides and sorts the array.
 *@array: array
 *@size: n of elements of the array
 */
void merge_sort_recursive(int *array, size_t size)
{
size_t mid;
int *left, *right;
if (size < 2)
	return;
mid = size / 2;
left = array;
right = array + mid;
merge_sort_recursive(left, mid);
merge_sort_recursive(right, size - mid);
merge(array, left, right, mid, size - mid);
}

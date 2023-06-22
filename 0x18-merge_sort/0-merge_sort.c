#include "sort.h"

/**
 *merge - Merges two arrays into one sorted array.
 *@arr: The main array.
 *@start: The start array.
 *@mid: The mid array.
 *@end: The end array.
 *@copy: copy.
 */

void merge(int *arr, int start, int mid, int end, int *copy)
{
	int s = start;
	int m = mid;
	int i = 0;

	for (i = start; i < end; i++)
	{
		if (s < mid && (m >= end || copy[s] <= copy[m]))
		{
			arr[i] = copy[s];
			s = s + 1;
		}
		else
		{
			arr[i] = copy[m];
			m = m + 1;
		}
	}
}

/**
 * split - split array
 * @arr: array to sort
 * @first: start index of the array
 * @last: end index of the array
 * @sorted_arr: sorted array
 */
void split(int *arr, int first, int last, int *sorted_arr)
{
	int mid;

	if (last - first <= 1)
		return;

	mid = (first + last) / 2;
	split(sorted_arr, first, mid, arr);
	split(sorted_arr, mid, last, arr);
	printf("Merging...\n");

	printf("[Left]: ");
	for (int i = first; i < mid; i++)
	{
		printf("%d", sorted_arr[i]);
		if (i < mid - 1)
			printf(", ");
	}

	printf("\n[Right]: ");
	for (int i = mid; i < last; i++)
	{
		printf("%d", sorted_arr[i]);
		if (i < last - 1)
			printf(", ");
	}
	merge(arr, first, mid, last, sorted_arr);

	printf("\n");
	printf("[Done]: ");
	for (int i = first; i < last; i++)
	{
		printf("%d", arr[i]);
		if (i < last - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 *merge_sort - Recursively divides and sorts the array.
 *@array: The array to be sorted.
 *@size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
	int *copy;
	size_t a = 0;

	copy = malloc(sizeof(int) * size);

	for (a = 0; a < size; a++)
		copy[a] = array[a];

	split(array, 0, size, copy);
	free(copy);
}

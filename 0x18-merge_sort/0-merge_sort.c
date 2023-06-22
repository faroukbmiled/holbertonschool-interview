#include "sort.h"

/**
 *merge - merge two arraies
 *@arr: array to sort
 *@start: a copy of the array to sort
 *@mid: start index
 *@end:  end index
 *@copy: mid index
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
 *split - split  array
 *@array: array to sort
 *@first: a copy of the array to sort
 *@last: start index of the array
 *@sorted_arr: end index of the array
 */
void split(int *arr, int first, int last, int *sorted_arr)
{
	int mid = (first + last) / 2;
	int i = 0;

	if (last - first <= 1)
		return;

	split(sorted_arr, first, mid, arr);
	split(sorted_arr, mid, last, arr);
	printf("Merging...\n");

	printf("[Left]: ");
	for (i = first; i < mid; i++)
	{
		printf("%d", sorted_arr[i]);
		if (i < mid - 1)
			printf(", ");
	}

	printf("\n[Right]: ");
	for (i = mid; i < last; i++)
	{
		printf("%d", sorted_arr[i]);
		if (i < last - 1)
			printf(", ");
	}

	merge(arr, first, mid, last, sorted_arr);

	printf("\n");
	printf("[Done]: ");
	for (i = first; i < last; i++)
	{
		printf("%d", arr[i]);
		if (i < last - 1)
			printf(", ");
	}

	printf("\n");
}

/**
 *merge_sort -  sort array using merge sort
 *@array: array to sort
 *@size: size of the array
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

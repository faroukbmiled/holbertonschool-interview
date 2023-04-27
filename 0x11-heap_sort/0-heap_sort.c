#include "sort.h"

/**
 *swap - Swaps two integers
 *
 *@a: First integer
 *@b: Second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 *sift_down - Performs the sift-down operation on the heap
 *
 *@array: The array to be sorted
 *@start: The start of the subtree to be sifted down
 *@end: The end of the subtree to be sifted down
 *@size: The size of the heap
 */
static void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;

	while ((2 * root + 1) <= end)
	{
		size_t child = 2 * root + 1;
		size_t swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx == root)
			return;

		swap(&array[root], &array[swap_idx]);
		print_array(array, size);

		root = swap_idx;
	}
}

/**
 *heap_sort - Sorts an array of integers in
 *ascending order using the Heap sort algorithm
 *
 *@array: The array to be sorted
 *@size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	size_t end = size - 1;

	for (int i = (end - 1) / 2; i >= 0; --i)
		sift_down(array, i, end, size);

	while (end > 0)
	{
		swap(&array[end], &array[0]);
		print_array(array, size);
		--end;
		sift_down(array, 0, end, size);
	}
}

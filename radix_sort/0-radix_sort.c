#include "sort.h"

/**
 *get_max - Returns the maximum element from an array
 *@array: The array to find the maximum element
 *@size: Number of elements in the array
 *Return: The maximum element
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 *radix_sort - Sorts an array of integers using the Radix sort algorithm
 *@array: The array to be sorted
 *@size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
	int *output;
	int max, exp;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);
	output = malloc(sizeof(int) * size);
	if (output == NULL)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		int count[10] = { 0 };

		size_t i;

		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		for (i = size - 1; i < SIZE_MAX; i--)
		{
			output[count[(array[i] / exp) % 10] - 1] = array[i];
			if (i == 0)
				break;
			count[(array[i] / exp) % 10]--;
		}

		for (i = 0; i < size; i++)
			array[i] = output[i];

		print_array(array, size);
	}

	free(output);
}

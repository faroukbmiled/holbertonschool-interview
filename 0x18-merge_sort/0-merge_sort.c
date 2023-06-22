#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

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
    int i;

    for (i = start; i < end; i++)
    {
        if (s < mid && (m >= end || copy[s] <= copy[m]))
        {
            arr[i] = copy[s];
            s++;
        }
        else
        {
            arr[i] = copy[m];
            m++;
        }
    }
}

/**
 * split - Split array recursively and merge the sorted subarrays.
 * @arr: The array to be sorted.
 * @first: The start index of the subarray.
 * @last: The end index of the subarray.
 * @sorted_arr: Temporary array for merging.
 */
void split(int *arr, int first, int last, int *sorted_arr)
{
    int mid, i;

    if (last - first > 1)
    {
        mid = (first + last) / 2;

        split(arr, first, mid, sorted_arr);
        split(arr, mid, last, sorted_arr);

        merge(arr, first, mid, last, sorted_arr);

        printf("Merging...\n");

        printf("[left]: ");
        for (i = first; i < mid; i++)
        {
            printf("%d", arr[i]);
            if (i < mid - 1)
                printf(", ");
        }
        printf("\n[right]: ");
        for (i = mid; i < last; i++)
        {
            printf("%d", arr[i]);
            if (i < last - 1)
                printf(", ");
        }
        printf("\n[Done]: ");
        for (i = first; i < last; i++)
        {
            printf("%d", arr[i]);
            if (i < last - 1)
                printf(", ");
        }
        printf("\n");
    }
}

/**
 * merge_sort - Recursively divides and sorts the array.
 * @array: The array to be sorted.
 * @size: The number of elements in the array.
 */
void merge_sort(int *array, size_t size)
{
    int *copy;
    size_t i;

    copy = malloc(sizeof(int) * size);
    if (copy == NULL)
        return;

    for (i = 0; i < size; i++)
        copy[i] = array[i];

    split(array, 0, size, copy);

    free(copy);
}

#include "slide_line.h"

/**
 *slide_line - Slide and merge an array of integers
 *@line: Pointer to the array of integers
 *@size: Number of elements in the array
 *@direction: SLIDE_LEFT or SLIDE_RIGHT
 *Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	perform_slide(line, size, direction);
	merge_adjacent(line, size);

	return (1);
}

/**
 *perform_slide - Move and merge the elements in the array
 *@line: Pointer to the array of integers
 *@size: Number of elements in the array
 *@direction: SLIDE_LEFT or SLIDE_RIGHT
 */
void perform_slide(int *line, size_t size, int direction)
{
	size_t current, destination;

	if (direction == SLIDE_RIGHT)
	{
		destination = size - 1;
		for (current = size - 2; current < size; --current)
		{
			if (line[current] == line[destination] && line[current])
				line[destination--] += line[current];
			else if (line[current] != line[destination] && line[current])
			{
				if (line[destination] != 0)
					destination--;
				if (line[destination] == 0)
					line[destination] = line[current];
			}
		}
	}
	else if (direction == SLIDE_LEFT)
	{
		destination = 0;
		for (current = 1; current < size; ++current)
		{
			if (line[current] == line[destination] && line[current])
				line[destination++] += line[current];
			else if (line[current] != line[destination] && line[current])
			{
				if (line[destination] != 0)
					destination++;
				if (line[destination] == 0)
					line[destination] = line[current];
			}
		}
	}
}

/**
 *merge_adjacent - Merge adjacent equal elements in the array
 *@line: Pointer to the array of integers
 *@size: Number of elements in the array
 */
void merge_adjacent(int *line, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; ++i)
	{
		if (line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}
}

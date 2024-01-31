#include "sandpiles.h"
#include <stdio.h>

/**
 *print_grid - print 3x3 grid
 *@grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}

		printf("\n");
	}
}

/**
 * topple - Redistributes grains to neighboring cells
 * @grid: 3x3 grid representing the sandpile
 * @i: Row index of the unstable cell
 * @j: Column index of the unstable cell
 */
static void topple(int grid[3][3], int i, int j)
{
	grid[i][j] -= 4;
	if (i - 1 >= 0)
		grid[i - 1][j] += 1;
	if (i + 1 < 3)
		grid[i + 1][j] += 1;
	if (j - 1 >= 0)
		grid[i][j - 1] += 1;
	if (j + 1 < 3)
		grid[i][j + 1] += 1;
}

/**
 * is_unstable - Checks if a cell in the sandpile grid has more than 3 grains.
 * @value: The value representing the number of grains in a cell
 *
 * Return: 1 if the cell is unstable (has more than 3 grains), 0 otherwise.
 */
static int is_unstable(int value)
{
	return (value > 3);
}

/**
 *sandpiles_sum - get sum of two sandpiles
 *@grid1: Left 3x3 grid
 *@grid2: Right 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int stable = 1;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
			if (is_unstable(grid1[i][j]))
				stable = 0;
		}
	}

	while (!stable)
	{
		printf("=\n");
		print_grid(grid1);

		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (is_unstable(grid1[i][j]))
				{
					topple(grid1, i, j);
				}
			}
		}

		stable = 1;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (is_unstable(grid1[i][j]))
					stable = 0;
			}
		}
	}
}

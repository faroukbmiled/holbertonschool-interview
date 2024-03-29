#include "menger.h"

/**
 *menger - draws a 2D Menger Sponge
 *@level: the level of the Menger Sponge to draw
 */
void menger(int level)
{
	int size, i, j, n;

	if (level < 0)
		return;

	size = (int) pow(3, level);

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			char print_char = '#';

			for (n = 1; n < size; n *= 3)
			{
				if ((i / n) % 3 == 1 && (j / n) % 3 == 1)
				{
					print_char = ' ';
					break;
				}
			}

			putchar(print_char);
		}

		putchar('\n');
	}
}

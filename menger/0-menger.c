#include <math.h>
#include <stdio.h>
#include "menger.h"

/**
 * menger - draws a 2D Menger sponge of a given level
 * @level: the level of the Menger sponge to draw
 *
 * Description: a cell is a hole (space) when, at any scale, its row and
 * column are both the center (index 1) of a 3x3 block; otherwise it is
 * filled with '#'. Does nothing if level is lower than 0.
 */
void menger(int level)
{
	int size, i, j, x, y, hole;

	if (level < 0)
		return;

	size = (int)pow(3, level);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			x = i;
			y = j;
			hole = 0;
			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					hole = 1;
					break;
				}
				x /= 3;
				y /= 3;
			}
			putchar(hole ? ' ' : '#');
		}
		putchar('\n');
	}
}


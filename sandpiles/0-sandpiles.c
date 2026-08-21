#include "sandpiles.h"
#include <stdio.h>

/**
 * print_grid - prints a 3x3 grid
 * @grid: the 3x3 grid to print
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
 * is_stable - checks whether a sandpile is stable
 * @grid: the 3x3 grid to check
 *
 * Return: 1 if stable (no cell above 3 grains), 0 otherwise
 */
static int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * topple - performs one toppling round on an unstable sandpile
 * @grid: the 3x3 grid to topple
 *
 * Description: uses a snapshot so every cell above 3 topples
 * simultaneously during the round.
 */
static void topple(int grid[3][3])
{
	int i, j;
	int copy[3][3];

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			copy[i][j] = grid[i][j];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (copy[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
					grid[i - 1][j] += 1;
				if (i < 2)
					grid[i + 1][j] += 1;
				if (j > 0)
					grid[i][j - 1] += 1;
				if (j < 2)
					grid[i][j + 1] += 1;
			}
		}
	}
}

/**
 * sandpiles_sum - computes the sum of two stable sandpiles
 * @grid1: first grid, also receives the stabilized result
 * @grid2: second grid to add to @grid1
 *
 * Description: adds @grid2 to @grid1, then topples @grid1 until it is
 * stable. Prints @grid1 before each toppling round while it is unstable.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];

	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
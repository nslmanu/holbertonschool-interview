#include "slide_line.h"

/**
 * compact_left - pushes all non-zero values to the left, fills with zeros
 * @line: the array of integers
 * @size: number of elements in line
 */
static void compact_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0, j = 0; i < size; i++)
		if (line[i] != 0)
			line[j++] = line[i];
	while (j < size)
		line[j++] = 0;
}

/**
 * merge_left - slides and merges identical adjacent values to the left
 * @line: the array of integers
 * @size: number of elements in line
 */
static void merge_left(int *line, size_t size)
{
	size_t i;

	compact_left(line, size);
	for (i = 0; i + 1 < size; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] += line[i + 1];
			line[i + 1] = 0;
		}
	}
	compact_left(line, size);
}

/**
 * reverse - reverses an array of integers in place
 * @line: the array of integers
 * @size: number of elements in line
 */
static void reverse(int *line, size_t size)
{
	size_t i;
	int tmp;

	for (i = 0; i < size / 2; i++)
	{
		tmp = line[i];
		line[i] = line[size - 1 - i];
		line[size - 1 - i] = tmp;
	}
}

/**
 * slide_line - slides and merges an array of integers (2048 mechanics)
 * @line: pointer to the array of integers
 * @size: number of elements in line
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_RIGHT)
	{
		reverse(line, size);
		merge_left(line, size);
		reverse(line, size);
	}
	else
	{
		merge_left(line, size);
	}

	return (1);
}

#include "palindrome.h"

/**
 * is_palindrome - checks whether an unsigned integer is a palindrome
 * @n: the number to be checked
 *
 * Description: compares the outermost digits and works inward, without
 * reversing the number, so it never overflows.
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long div = 1, left, right;

	while (n / div >= 10)
		div *= 10;

	while (n > 0)
	{
		left = n / div;
		right = n % 10;
		if (left != right)
			return (0);
		n = (n % div) / 10;
		div /= 100;
	}

	return (1);
}

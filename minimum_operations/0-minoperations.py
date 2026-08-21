#!/usr/bin/python3
"""Module that computes the fewest operations to reach n identical chars."""


def minOperations(n):
    """Return the minimum number of Copy All / Paste operations to get n chars.

    Starting from a single character, the only moves are Copy All then Paste.
    The minimum number of operations equals the sum of the prime factors of n.

    Args:
        n (int): the target number of characters.

    Returns:
        int: the minimum number of operations, or 0 if n is not reachable.
    """
    if not isinstance(n, int) or n < 2:
        return 0

    operations = 0
    divisor = 2
    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1
    return operations

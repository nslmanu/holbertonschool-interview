#!/usr/bin/python3
"""Reads logs from stdin and computes metrics line by line."""
import sys


def print_stats(total_size, status_counts):
    """Print the accumulated statistics.

    Args:
        total_size (int): the sum of all file sizes seen so far.
        status_counts (dict): counts of each valid status code.
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_counts):
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


if __name__ == "__main__":
    total_size = 0
    line_count = 0
    codes = [200, 301, 400, 401, 403, 404, 405, 500]
    status_counts = {code: 0 for code in codes}

    try:
        for line in sys.stdin:
            parts = line.split()
            line_count += 1

            if len(parts) > 2:
                try:
                    status = int(parts[-2])
                    if status in status_counts:
                        status_counts[status] += 1
                except ValueError:
                    pass
                try:
                    total_size += int(parts[-1])
                except ValueError:
                    pass

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

        print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise

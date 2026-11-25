#!/usr/bin/python3
"""Solves the N queens puzzle.

Places N non-attacking queens on an N*N chessboard and prints every
possible solution, one per line, using a backtracking search.
"""
import sys


def solve(n, row, cols, diag1, diag2, board, solutions):
    """Recursively places queens row by row using backtracking.

    Args:
        n (int): the board size and number of queens.
        row (int): the current row being filled.
        cols (set): columns already occupied by a queen.
        diag1 (set): occupied "/" diagonals (row - col).
        diag2 (set): occupied "\\" diagonals (row + col).
        board (list): board[r] holds the column of the queen in row r.
        solutions (list): collects every complete solution found.
    """
    if row == n:
        solutions.append([[r, board[r]] for r in range(n)])
        return
    for col in range(n):
        if col in cols or (row - col) in diag1 or (row + col) in diag2:
            continue
        cols.add(col)
        diag1.add(row - col)
        diag2.add(row + col)
        board[row] = col
        solve(n, row + 1, cols, diag1, diag2, board, solutions)
        cols.discard(col)
        diag1.discard(row - col)
        diag2.discard(row + col)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        N = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if N < 4:
        print("N must be at least 4")
        sys.exit(1)

    results = []
    solve(N, 0, set(), set(), set(), [0] * N, results)
    for solution in results:
        print(solution)

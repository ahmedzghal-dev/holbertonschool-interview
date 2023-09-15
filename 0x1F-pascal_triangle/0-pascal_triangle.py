#!/usr/bin/python3
"""
function def pascal_triangle(n):
that returns a list of lists of integers
"""


def pascal_triangle(n):
    """  Triangle of size n """
    if n <= 0:
        return []

    pascal = [[1]]
    while len(pascal) != n:
        previous = pascal[-1]
        current = [1]
        for i in range(len(previous) - 1):
            current.append(previous[i] + previous[i + 1])
        current.append(1)
        pascal.append(current)
    return pascal

#!/usr/bin/python3

"""
method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""


def minOperations(n):
    counter = 0
    i = 1
    a = 0
    while i < n:
        if n % i == 0:
            a = i
            counter = counter + 1
            i = i * 2
        else:
            i += a
        counter += 1

    return counter

#!/usr/bin/python3

"""
method that calculates the fewest number of operations
needed to result in exactly n H characters in the file.
"""

def minOperations(n):
    counter = 0
    i = 1
    while (n):
        while i < n:
            if (i % 2 != 0):
                a = i
                counter = counter + 2
                i = i * 2
                if i + (a * 2) == n:
                    counter = counter + 2
                    return counter
            if (i % 2 == 0):
                counter = counter + 1
                i = i + a
                a = i
        return counter
    return 0
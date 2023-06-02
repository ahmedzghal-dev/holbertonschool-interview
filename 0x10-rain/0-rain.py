#!/usr/bin/python3
"""
Module used to
"""


def rain(arr):
    """
    Given a list of non-negative integers representing the heights
    of walls with unit width 1, as if viewing the cross-section of
    a relief map, calculate how many square units of water will be
    retained after it rains
    """

    if (arr is None):
        return 0

    if not (isinstance(arr, list)):
        return 0

    n = len(arr)
    if (n < 2):
        return 0

    if not all(isinstance(n, int) for n in arr):
        return 0

    if (len([num for num in arr if num < 0]) > 0):
        return 0

    rain = 0
    for i in range(1, n - 1):

        left = arr[i]
        for j in range(i):
            left = max(left, arr[j])

        right = arr[i]
        for j in range(i + 1, n):
            right = max(right, arr[j])

        rain += (min(left, right) - arr[i])

    return rain
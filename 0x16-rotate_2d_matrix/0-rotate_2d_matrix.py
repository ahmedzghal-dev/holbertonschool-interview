#!/usr/bin/python3
"""
Defines function that can rotate 2D NxN matrix 90 degrees clockwise in place
"""


def rotate_2d_matrix(matrix):
    """
    Rotates 2D NxN matrix 90 degrees clockwise in place
    parameters:
        matrix [list of lists of ints]:
            matrix to rotate
            can be assumed to have 2 dimensions and will not be empty
    """
    n = len(matrix)

    # Step 1: Transpose the matrix
    for i in range(n):
        for j in range(i + 1, n):
            matrix[i][j], matrix[j][i] = matrix[j][i], matrix[i][j]

    # Step 2: Reverse each row
    for i in range(n):
        matrix[i] = matrix[i][::-1]

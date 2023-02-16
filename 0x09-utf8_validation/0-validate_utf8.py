#!/usr/bin/python3
"""
Determines if the given data set represents a valid UTF-8 encoding.

Args:
    data (list[int]): A list of integers representing
    the bytes of the data set.

Returns:
    bool: True if the data set is a valid
    UTF-8 encoding, False otherwise.
    """


def validUTF8(data):
    """
    Returns:
    bool: True if the data set is a valid
    UTF-8 encoding, False otherwise.
    """
    i = 0
    while i < len(data):
        count = 0
        mask = 1 << 7
        while mask & data[i]:
            count += 1
            mask >>= 1
        if count == 0:
            pass
        elif count == 1 or count > 4:
            return False
        else:
            for j in range(i + 1, i + count):
                if j >= len(data) or (data[j] >> 6) != 2:
                    return False
            i += count - 1
        i += 1
    return True

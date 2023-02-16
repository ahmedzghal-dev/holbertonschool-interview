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
    num_bytes = 0
    for byte in data:
        # If the most significant bit is 0, this is a single-byte character
        if byte >> 7 == 0:
            if num_bytes != 0:
                return False
        # If the most significant bits are 110, this is a two-byte character
        elif byte >> 5 == 0b110:
            if num_bytes != 0:
                return False
            num_bytes = 1
        # If the most significant bits are 1110, this is a three-byte character
        elif byte >> 4 == 0b1110:
            if num_bytes != 0:
                return False
            num_bytes = 2
        # If the most significant bits are 11110, this is a four-byte character
        elif byte >> 3 == 0b11110:
            if num_bytes != 0:
                return False
            num_bytes = 3
        else:
            # Invalid most significant bits
            return False

        # For each additional byte in a multi-byte character,
        # the two most significant bits must be 10
        if num_bytes > 0:
            num_bytes -= 1
            if byte >> 6 != 0b10:
                return False

        # If there are still bytes left in a multi-byte character,
        # this is an invalid encoding
        if num_bytes > 0:
            return False

        return True

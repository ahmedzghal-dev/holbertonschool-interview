#include "holberton.h"

/**
 * wildcmp - compares two strings and returns 1 if the strings
 * @s1: string to compare to
 * @s2: string with wild character
 *
 * Return: On success 1.
 */

int wildcmp(char *s1, char *s2)
{
    if (*s1 == '\0')
    {
        if (*s2 == '\0')
            return 1;
        if (*s2 == '*')
            return wildcmp(s1, s2 + 1);
        return 0;
    }

    if (*s2 == '*')
        return wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1);

    if (*s1 == *s2)
        return wildcmp(s1 + 1, s2 + 1);

    return 0;
}

#include "slide_line.h"
#define SLIDE_LEFT 0
#define SLIDE_RIGHT 1

/**
 * slide_line - slides and merges an array of integers
 * @line: pointer to array of integers
 * @size: number of elements in @line
 * @direction: direction to slide and merge (@SLIDE_LEFT or @SLIDE_RIGHT)
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j, k;

    if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
        return 0;

    if (direction == SLIDE_LEFT)
    {
        for (i = 0, j = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (i != j)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j++;
            }
        }

        for (i = 0; i < size - 1; i++)
        {
            if (line[i] > 0 && line[i] == line[i + 1])
            {
                line[i] *= 2;
                line[i + 1] = 0;
            }
        }

        for (i = 0, j = 0; i < size; i++)
        {
            if (line[i] != 0)
            {
                if (i != j)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j++;
            }
        }
    }
    else
    {
        for (i = size - 1, j = size - 1; (int)i >= 0; i--)
        {
            if (line[i] != 0)
            {
                if (i != j)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j--;
            }
        }

        for (i = size - 1; i > 0; i--)
        {
            if (line[i] > 0 && line[i] == line[i - 1])
            {
                line[i] *= 2;
                line[i - 1] = 0;
            }
        }

        for (i = size - 1, j = size - 1; (int)i >= 0; i--)
        {
            if (line[i] != 0)
            {
                if (i != j)
                {
                    line[j] = line[i];
                    line[i] = 0;
                }
                j--;
            }
        }
    }

    return 1;
}
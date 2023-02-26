#ifndef SLIDE_TLINE_H_
#define SLIDE_TLINE_H_

#include <stddef.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>

#define SLIDE_LEFT 0
#define SLIDE_RIGHT 

static void print_array(int const *array, size_t size);
int slide_line(int *line, size_t size, int direction);




#endif
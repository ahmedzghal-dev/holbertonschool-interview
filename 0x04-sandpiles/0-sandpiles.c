#include <stdlib.h>
#include <stdio.h>

/**
 * print_grid_sum - Print 3x3 grids sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 *
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3]) {
    int i, j;

    // Add grid2 to grid1
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            grid1[i][j] += grid2[i][j];
        }
    }

    // Check if grid1 is stable
    while (!is_stable(grid1)) {
        printf("=\n");
        print_grid(grid1);

        // Copy the current state of grid1 to a temporary grid
        int temp[3][3];
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                temp[i][j] = grid1[i][j];
            }
        }

        // Topple any unstable cells in grid1
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (temp[i][j] > 3) {
                    int diff = temp[i][j] - 3;
                    grid1[i][j] = diff;

                    // Distribute grains to adjacent cells
                    if (i > 0) {
                        grid1[i - 1][j] += diff;
                    }
                    if (i < 2) {
                        grid1[i + 1][j] += diff;
                    }
                    if (j > 0) {
                        grid1[i][j - 1] += diff;
                    }
                    if (j < 2) {
                        grid1[i][j + 1] += diff;
                    }
                }
            }
        }
    }
}
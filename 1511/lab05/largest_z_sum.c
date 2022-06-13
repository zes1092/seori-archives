// largest_z_sum 
// largest_z_sum.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 15/03/2022
//
// Program adds two numbers together, but in an array.
// Find the largest sum of numbers in a z shape.

#include <stdio.h>
#include <assert.h>

#define MAX_SIZE 100

int largest_z_sum(int size, int array[MAX_SIZE][MAX_SIZE]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(void) {
    int array[MAX_SIZE][MAX_SIZE];
    
    // Get the array size.
    int size;
    printf("Enter 2D array side length: ");
    scanf("%d", &size);
    assert(size >= 3);

    // Scan in values for the array.
    printf("Enter 2D array values:\n");
    int i = 0;
    while (i < size) {
        int j = 0;
        while (j < size) {
            assert(scanf("%d", &array[i][j]) == 1);
            j++;
        }
        i++;
    }

    printf("The largest z sum is %d.\n", largest_z_sum(size, array));

    return 0;
}

// Return the largest sum of numbers in a z shape.
int largest_z_sum(int size, int array[MAX_SIZE][MAX_SIZE]) {
    // Put your code here.
    int min_size = 3; 

    int max_sum = array[0][0] + array[0][1] + array[0][2] + array[1][1] + array[2][0] + array[2][1] + array[2][2];
    
    while (min_size <= size) { 
        int x_row = 0; 
        while (x_row <= size - min_size) { 
            int y_col = 0; 
            while (y_col <= size - min_size) { 
                int top_row = 0; 
                int i = 0; 
                while (i < min_size - 1) { 
                    top_row += array[x_row][y_col + i]; 
                    i += 1; 
                }
                int diagonal = 0; 
                i = 0; 
                while (i < min_size) { 
                    diagonal += array[x_row + i][y_col + (min_size - 1) - i];
                    i += 1;  
                }
                int bottom_row = 0; 
                i = 1; 
                while (i < min_size) { 
                    bottom_row += array[x_row+ (min_size - 1)][y_col + i]; 
                    i += 1; 
                }
                int total = top_row + bottom_row + diagonal; 
                if (total > max_sum) { 
                    max_sum = total; 
                }
                y_col += 1; 
            } 
            x_row += 1; 
        }
        min_size += 1; 
    }
    return max_sum;
}
// Program to print out an hourglass shape given an
// input size.
// Written by Rory Golledge (June)

#include <stdio.h>

int main(void) {
    int input;
    printf("Please enter a size: ");
    scanf("%d", &input);

    int row = 0;
    while (row < input) {
        int col = 0;
        while (col < input) {
            // Take care of Top-half triangle
            if (row < input / 2) {
                if (row <= col && row + col <= input - 1) {
                    printf("*");
                } else {
                    printf("-");
                }
            }
            // Take care of Bottom-half triangle
            else {
                if (row >= col && row + col >= input - 1) {
                    printf("*");
                } else {
                    printf("-");
                }
            }

            col++;
        }
        printf("\n");
        row++;
    }

    return 0;
}
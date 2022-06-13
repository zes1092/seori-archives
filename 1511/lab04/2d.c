// This program prints out a 2D array
// Remember that a 2D array is initialised with size:
// array[row][col], where:
// row is the outer loop 
// col is the inner loop 

// Intro 2D Arrays
// Sasha Vassar Week 4, Lecture 7


#include <stdio.h>

int main(void) {
    
    int array[3][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}};
    
    // int array[3] = {3, 2, 1}
    int row = 0;
    while (row < 3){
        int col = 0;
        while (col < 4){
            printf("%d", array[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }
    return 0;
}



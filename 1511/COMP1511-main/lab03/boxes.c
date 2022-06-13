// boxes
// boxesc
// 
// This program was written by Ze Sheng (z5421872)
// on 02/03/2022
// 
// Program which reads in a number and then draws 
// that many square boxes inside each other using asterisks. 

#include <stdio.h> 

int main(void) {
    int size; 

    printf("How many boxes: "); 
    scanf("%d", &size); 

    if (size > 50) {
        return 1; 
    }

    int number = size * 4 - 1; 

    int col = 0; 
    while (col < number) { 
        int row = 0; 
        while (row < number) { 
            int row_1 = (number - 1) - row; 
            int col_1 = (number - 1) - col; 

            if ((col == row) || (col == row_1)) { 
                if (col % 2 == 0) { 
                    printf("*"); 
                } else { 
                    printf("-"); 
                }
            } else if ((row < col) && (row > col_1) && (col % 2 == 0)) {
                 printf("*"); 
            } else if ((col > row) && (col < row_1) && (row % 2 == 0)) {
                 printf("*"); 
            } else if ((col < row) && (col > row_1) && (row % 2 == 0)) {
                 printf("*"); 
            } else if ((row > col) && (row < col_1) && (col % 2 == 0)) {
                 printf("*"); 
            } else { 
                printf("-");
            } 
            row += 1; 
        }
        printf("\n"); 
        col += 1; 
    }
    return 0; 
}


// x
// x.c
// 
// This program was written by Ze Sheng (z5421872)
// on 02/03/2022
// 
// A program that reads an integer n from standard input, 
// and prints an nxn pattern of asterisks and dashes in the shape of an "X".

#include <stdio.h> 

int main(void) { 
    int size; 

    printf("Enter size: "); 
    scanf("%d", &size); 

    if ((size < 5) || (size % 2 != 1)) {
        return 1; 
    } 
    
    int x = 0; 
    while (x < size) { 
        int y = 0; 
        while (y < size) {
            if ((x == y) || (x == size - (y + 1))) { 
                printf("*"); 
            } else { 
                printf("-");
            }
            y += 1; 
        }
        printf("\n"); 
        x += 1; 
    } 
    return 0; 
} 
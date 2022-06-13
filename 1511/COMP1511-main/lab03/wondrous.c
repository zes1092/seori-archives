// wondrous
// wondrous.c
// 
// This program was written by Ze Sheng (z5421872)
// on 02/03/2022
// 
// Program that reads a positive integer n from standard input, and prints the wondrous numbers of it as a graph of asterisks.

#include <stdio.h>  
 
int main(void) { 
    int num; 
    printf("What number would you like to see: "); 
    scanf("%d", &num); 

    int y = 0; 
    while (num > 1) {
        int x = 0; 
        if (num % 2 == 0) {
            while (x < num) { 
                printf("*"); 
                x += 1;
            }   
            num = num / 2; 
        } else if (num == 1) {
            return 1; 
        } else { 
            while (x < num) { 
                printf("*"); 
                x += 1;
            } 
            num = 3 * num + 1; 
        }
        printf("\n"); 
        y += 1; 
    }
    return 0; 
}


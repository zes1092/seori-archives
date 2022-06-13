// negative 
// negative.c
// 
// This program was written by Ze Sheng (z5421872)
// on 27/02/2022
// 
// A program to check if a number is postive, zero or negative.

#include <stdio.h> 

int main (void) { 
    int num; 

    scanf("%d", &num);

    if (num > 0) { 
        printf("You have entered a positive number.\n");
    } else if (num == 0) {
        printf("You have entered zero.\n");  
    } else { 
        printf("Don't be so negative!\n");
    }
    return 0;
}
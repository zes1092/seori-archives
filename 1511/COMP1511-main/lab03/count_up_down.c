// count_up_down
// count_up_down.c
// 
// This program was written by Ze Sheng (z5421872)
// on 02/03/2022
// 
// A program that reads one integer n and prints all integers from 0 to n inclusive one per line.

#include <stdio.h> 

int main(void) { 
    int number; 

    printf("Enter number: "); 
    scanf("%d", &number); 

    int count = 0; 
    while (count <= number) {
        printf("%d\n", count);  
        count += 1;
        if (count > number) { 
            return 1; 
        }
    }
    while (count >= number) {
        printf("%d\n", count);  
        count -= 1;
        if (count < number) { 
            return 1; 
        }
    }
    return 0; 
}

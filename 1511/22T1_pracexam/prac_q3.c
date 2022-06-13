// Exam Practice Question 3
// prac_q3.c
//
// This program was written by Ze Sheng (z5421872)
// on 22/04/2022
//
// Program reads integers and print out every integer at an even index 
// then prints out every integer at an odd index. 

#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

int main(void) { 
    int num[MAX];
    int new_num[MAX]; 

    int i = 0; 
    int length = 0; 

    while (i < MAX) { 
        scanf("%d", &num[i]); 
        if (num[i] == 0) { 
            i = MAX; 
        } else { 
            i++; 
            length++; 
        }
    } 

    i = 0; 
    int even = 0; 
    while (even < length && num[even] != 0) {
        new_num[i] = num[even]; 
        even += 2;  
        i += 1; 
    }

    int odd = 1; 
    while (odd < length && num[odd] != 0) {
        new_num[i] = num[odd]; 
        odd += 2;  
        i += 1; 
    }

    i = 0; 
    while (i < length) { 
        printf("%d ", new_num[i]); 
        i++; 
    }
    printf("\n"); 

    return 0;
}

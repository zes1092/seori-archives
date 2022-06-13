// reverse_array 
// reverse_array.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 7/03/2022
//
// Program which reads integers line by line, and when it reaches the end of input
// prints those integers in reverse order, line by line.

#include <stdio.h> 

#define MAX_NUM 100 

int main(void) { 
    int i = 0; 
    int scan_value = 0; 
    int value; 
    int scanned_num[MAX_NUM]; 

    printf("Enter numbers forwards:\n"); 
    
    while (scanf("%d", &value) == 1) { 
        scanned_num[i] = value; 
        scan_value = 1; 
        i += 1; 
    }
    
    printf("Reversed:\n"); 

    while (i > 0 && scan_value) { 
        i -= 1; 
        printf("%d\n", scanned_num[i]); 
    }
    return 0; 
}
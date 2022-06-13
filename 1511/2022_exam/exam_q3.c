// Starter code for exam_q3.

#include <stdio.h>

#define MAX 10000

int main(void) {
    // Add code to the main function to implement exam_q3!
    int num[MAX];

    int i = 0; 
    int length = 0; 
    int j = 0; 

    while (i < MAX) { 
        scanf("%d", &num[i]); 
        
        j = 0; 
        while (j < length) {
            if (num[j] == num[i]) {   
                printf("%d is repeated\n", num[i]); 
                return 0; 
            }
            j++; 
        }
        length++;
        i++; 
    } 

    return 0;
}

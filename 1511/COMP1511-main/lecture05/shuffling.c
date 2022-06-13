// I have changed my mind this morning on the best example, so this example
// is right now different to the problem on the slides.

// This program reads in three values and continually swaps them....


#include <stdio.h>

void shuffle (int *num1_ptr, int *num2_ptr);

int main(void) {
    int num1;
    int num2;
    int num3;
    
    
    printf("Please enter three numbers: ");
    
    while ((scanf("%d %d %d", &num1, &num2, &num3) == 3)) {
        printf("The numbers are: %d %d %d\n", num1, num2, num3);
  
        shuffle(&num1, &num2);
        printf("The numbers are: %d %d %d\n", num1, num2, num3);

        shuffle(&num2, &num3);
        
         printf("The numbers are: %d %d %d\n", num1, num2, num3);
        shuffle(&num3, &num1); 
         printf("The numbers are: %d %d %d\n", num1, num2, num3);
    }
    
    
    return 0;
}

void shuffle (int *num1_ptr, int *num2_ptr){
    int temp;
    temp = *num1_ptr;
    *num1_ptr = *num2_ptr;
    *num2_ptr = temp;
}


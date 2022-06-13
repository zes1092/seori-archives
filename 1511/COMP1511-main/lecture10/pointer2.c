// Program to demonstrate the use of pointers in functions
// 

#include <stdio.h>

// Function to add two to the sum
int sumPlusTwo(int *number1, int *number2){    
    // TODO: Add what is returned if we want to return result of sum + 2
    return  *number1 + *number2 + 2;
}

// Function to add 1 to a number
void numPlusOne(int *number1){
    // TODO: Don't need to return because modifying at the address directly
    // how to add 1 to the number?
    *number1 = *number1 + 1;
   
}

// Function to swap values at two memory addresses
void swap (int *number1, int *number2){
    int temp = *number1;
    *number1 = *number2;
    *number2 = temp;
}

// Main function for testing out this random program
int main(void){

    int num1 = 42;
    int num2 = 10;
    
    printf("%d + %d + 2 = %d\n", num1, num2, sumPlusTwo(&num1, &num2)); 
    swap(&num1, &num2);
    numPlusOne(&num1); 
    numPlusOne(&num1);
    printf("%d + %d + 2 = %d\n", num1, num2, sumPlusTwo(&num1, &num2)); 
    
    return 0;
}

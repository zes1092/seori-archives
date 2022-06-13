// This program demonstrates the use of a pointer
// This is a basic example that can be done without
// the use of pointers

// Sasha Vassar, Week 4 Lecture 8

#include <stdio.h>

void incrementer(int *pointer);

int main(void) {

    int number;
    // TODO: Declare a pointer, point to the address of number
    int *number_ptr = &number;
    printf("Enter number to increment: ");
    scanf("%d", &number);
    
    printf("The original number is %d\n", number);
    
    // TODO: Call the function to increment the number and give
    // it a pointer
    incrementer(number_ptr);
   
    printf("The number is now incremented to: %d\n", number);

    return 0;
}

// TODO: Write a function to increment the number by one
// Use a pointer so as not to return anything from the function
// Output: void
// Input: *pointer
// name of function: incrementer
void incrementer(int *pointer) {
    *pointer = *pointer + 1;
}

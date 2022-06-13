// Program that demonstrates basic pointer "fun"
//
// Sasha Vassar, Week 5 Lecture 9

#include <stdio.h>

int main(void) {
    int number = 6;
    int *number_ptr = NULL;
    
    int number_two = 13;
    int *number_two_ptr = NULL;
    
    // Print out the two variables 
    printf("number = %d\nnumber_two = %d\n", number, number_two);

    // Initialise the pointers to store address of variables
    number_ptr = &number;
    number_two_ptr = &number_two;
    
    // Print out the dereferenced pointers to see what is stored in the pointer 
    // and dereference pointer
    printf("Dereferenced number_ptr %d at address %p\n", *number_ptr, number_ptr);
    printf("Dereferenced number_two_ptr %d at address %p\n", *number_two_ptr, number_two_ptr);
        
     // Play with the dereferenced pointer to change the value stored in the 
     // variable   
    
    *number_ptr = *number_ptr + 6;
    
    printf("The number is %d\n", number);
    
    // TODO: Some more playing with pointers to change the value stored in the 
    // second pointer (dereferenced) to the sum of values in both variables
    
    *number_two_ptr = *number_two_ptr % 2;    
    printf("The number is %d\n", number_two);
    
    return 0;

}
        
// This program shows a very basic example of a pointer
// and what it is

// Sasha Vassar Week 4, Lecture 8


#include <stdio.h>

int main(void) {

    int box = 6;
    
    // TODO: 1. declaring a pointer, pointing at the address of box
    int *box_ptr = &box;
    // TODO: 2. Initialize the pointer, using & to get the address
    
    
    // TODO: %p means "pointer" (so it will print out the pointer
    // itself)
    // 3. * means "dereference"
    printf("The value of the variable box located at address %p is %d\n", box_ptr, *box_ptr);
    return 0;   
}
// This program shows that an array is not a pointers
// But it decays to a pointer to the first element of the 
// array by the compiler

#include <stdio.h>

int main (void) {
    
    int array[4] = {0};
    // Loop through the array and print out the address of 
    // each of the elements of the array
    int i = 0;
    while (i < 4) {
        printf("The memory address of array[%d] is %p\n", i, &array[i]);
        i++;
    }
    
    // Now print out the ADDRESS of the array by referencing
    // with the name of the array only. What do you notice?
    printf("The memory address of the array is %p\n", array);
    return 0;
    
}


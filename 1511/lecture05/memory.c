// This program gives an example of how you can allocate memory
// for an array and then read in the array and print it out in 
// reverse order.

// From previous weeks, do you remember that the only way to give an array
// necessary space is really to guess the size needed - so often we will guess
// a huge number and waste a lot of space... What if we knew the size of the
// array and could give memory based on size of the array?

// Sasha Vassar Week 5 Lecture 10

#include <stdio.h>

//malloc() and free() live inside the <stdlib.h>
#include <stdlib.h>

void read_array(int *numbers, int size);
void reverse_array(int *numbers, int size);

int main (void) {
    
    // Find out the size of the array:
    int size;
    printf("How many numbers would you like to scan: ");
    scanf("%d", &size);
    
    // Allocate some memory space for my array and return a pointer
    // to the first element
    int *numbers = malloc(size * sizeof(int));
    
    
    // Check if there is actually enough space to allocate
    // memory, exit the program if there is not enough memory
    // to allocate.
    if (numbers == NULL) {
        printf("Malloc failed, there is not enough memory to allocate\n");
        return 1;
    }    
    
    //Perform some functions here  
    read_array(numbers, size);
    reverse_array(numbers, size);
  
    // Free the allocated memory
    // (In this case, it would happen on program exit anyway)
    free(numbers);
    return 0;
}

//Helper function that reads in numbers and places them into an array
void read_array(int *numbers, int size) {
    int i = 0;
    while (i < size) {
        printf("Please enter a number: ");
        scanf("%d", &numbers[i]);
        i++;
    }
}



//TODO: Finish the helper function to reverse the elements of the array
void reverse_array(int *numbers, int size) {
    printf("Numbers reversed are:\n");
    int last = size - 1;
    while (last >= 0) {
        printf("%d\n", numbers[last]);
        last--;
    }
}




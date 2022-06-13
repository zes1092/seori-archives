// Practice Question 1 COMP1511 EXAM
// prac_q1.c
//
// This program was written by Ze Sheng (z5421872)
// on 22/04/2022
//
// Program sums all the negative x coordinates, and all the positive y coordinates.

#include <stdio.h>
#include <stdlib.h>


struct coordinate {
    int x;
    int y;
};


// Return the sum of all negative x coordinates 
// and all positive y coordinates as a struct 
struct coordinate sum_coords(int size, struct coordinate array[size]){

    // PUT YOUR CODE HERE AND CHANGE THE RETURN VALUE
    int i = 0; 
    struct coordinate sum_coordinate; 
    sum_coordinate.x = 0; 
    sum_coordinate.y = 0; 
    while (i < size) { 
        if (array[i].x < 0) { 
            sum_coordinate.x += array[i].x; 
        }
        if (array[i].y > 0) { 
            sum_coordinate.y += array[i].y; 
        }
        i++; 
    }
    return sum_coordinate; 
}

// This is a simple main function which could be used
// to test your sum_cood function.
// It will not be marked.
// Only your sum_cood function will be marked.

#define TEST_ARRAY_SIZE 3

int main(void) {
    struct coordinate test_array[TEST_ARRAY_SIZE] = {
        { .x = -3, .y = 20},
        { .x = 10, .y = -20},
        { .x = -5, .y = 50}
    };
    struct coordinate result = sum_coords(TEST_ARRAY_SIZE, test_array);
    printf("(%d, %d)\n", result.x, result.y);

    return 0;
}

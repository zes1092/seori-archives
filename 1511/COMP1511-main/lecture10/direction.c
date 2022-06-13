// Print out the total of the number of steps taken in a
// specific direction. So for example, if direction is 'l', find all
// the structs with direction as 'l' and add the numbers in
// those structs up. Edit the function int total ....

#include <stdio.h>

#define MAX 100

struct direction {
    int number;
    char dir;
};


// Return the number of total steps taken in a particular direction
int total (int size, struct direction array[MAX]) {
 
    // TODO: Write the function to calculate total number of steps
    // in a particular direction
    char temp;
    printf("What direction would you like to sum: ");
    scanf(" %c", &temp);
    int total_steps = 0;
    int i = 0;
    while (i < size) {
        if (array[i].dir == temp) {
            total_steps = total_steps + array[i].number;
        }
        i++;
    }      
    return total_steps;
}

// This is a simple main function which could be used
// to test your total function.
// It will not be marked.
// Only your total function will be marked.

#define TEST_ARRAY_SIZE 3

int main(void) {
    struct direction test_array[TEST_ARRAY_SIZE] = {
        { .number = 10, .dir = 'l'},
        { .number = 25, .dir = 'r'},
        { .number = 15, .dir = 'l'}
    };
    printf("The total number of steps is: %d\n", total(TEST_ARRAY_SIZE, test_array));

    return 0;
}
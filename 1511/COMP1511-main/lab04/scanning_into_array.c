// scanning_into_array 
// scanning_into_array.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 7/03/2022
//
// Program which scans in a certain amount of numbers from user and fills an array

#include <stdio.h>

#define MAX_SIZE 100

// Given an integer array, iterate over the array and print the minimum and
// maximum values in the array.
void print_array_minmax(int length, int arr[MAX_SIZE]);

int main(void) {
    int arr[MAX_SIZE]; 
    printf("How many numbers: ");
    int length = 0; 
    // TODO: Fill in code that takes the quantity of numbers from the user;
    scanf("%d", &length);
    printf("Please enter numbers: ");
    // TODO: Fill in code that scans in integers from the use
    int i = 0; 
    while (i < length) { 
        scanf("%d", &arr[i]); 
        i += 1; 
    }
    print_array_minmax(length, arr);
    // TODO: Change this statement to match your variables and array.
    //      Refer to the documentation below for correct usage!

    return 0;
}

//////////////////////// DO NOT CHANGE THE CODE BELOW! ////////////////////////

// Given an integer array, iterate over the array and print the minimum and
// maximum values in the array.
//
// Takes in:
// - `length` -- The length of the array.
// - `arr[MAX_SIZE]` -- The integer array to iterate over.
//
// Returns: nothing.
void print_array_minmax(int length, int arr[MAX_SIZE]) {
    int index = 0;
    if (length > 0) {
        int minimum = arr[index];
        int maximum = arr[index];

        while (index < length) {
            if (arr[index] < minimum) {
                minimum = arr[index];
            } else if (arr[index] > maximum) {
                maximum = arr[index];
            }
            
            index++;
        }

        printf("Minimum: %d\nMaximum: %d\n", minimum, maximum);
    }
    
    return;
}


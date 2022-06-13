// This program allows a user to input ten numbers and then 
// finds the smallest number out of these. 

// Revisiting 1D arrays
// Sasha Vassar Week 4, Lecture 7



// Problem: A user is asked to enter 10 positive numbers. 
// We will then go through these numbers and find the 
// lowest number and output what the lowest number is 
// to the user.

// 1) Scanf in while loop to take in 10 numbers
// 2) Store in an array 
// 3) Find the lowest of the numbers
// 4) Output the lowest number to terminal
  

#include <stdio.h>

#define MAX_NUMBER 10 

int lowest_number(int number[MAX_NUMBER]);


int main (void) {

    int numbers[MAX_NUMBER] = {0};
    
    int i = 0;
    while (i < MAX_NUMBER){
        printf("Please enter a number: ");
        scanf("%d", &numbers[i]);
        i++;
    }
    
    int lowest = lowest_number(numbers);

    printf("The lowest number is: %d\n", lowest);

    return 0;
}

// Let's write a function that finds the 
// lowest number in an array
// INPUT to function: array of numbers  
// OUTPUT to function: int (lowest number) 
// name of function: lowest_number

int lowest_number(int number[MAX_NUMBER]){

    int lowest_number = number[0];
    
    int i = 0;
    while (i < MAX_NUMBER){
        if (number[i] < lowest_number) {
            lowest_number = number[i];
        }
        i++;
    }
    return lowest_number;
}






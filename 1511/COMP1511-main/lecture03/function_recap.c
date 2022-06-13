// Recap of functions
// How do we separate blocks of code into functions
// Example is calculating the sum of numbers

// Sasha Vassar Week 3, Lecture 6

#include <stdio.h>

int sum(int num1, int num2);
void print(int result);

int main(void) {
    int number_one;
    int number_two;
     
    printf("Enter the first number: ");
    scanf("%d",&number_one);
    printf("Enter the second number: ");
    scanf("%d",&number_two);

    sum(number_one, number_two);
    
    return 0;
}

// Let's create a function to add two numbers together
// INPUT, OUTPUT, name of the function
// INPUT: two ints
// OUTPUT: one int
// name of function: sum
int sum(int num1, int num2){
    int result = num1 + num2;
    print(result); 
    return 0;
    //return result; //integer
    // return (number_one + number_two);
}

void print(int result){
    printf ("Sum is: %d\n", result);
}









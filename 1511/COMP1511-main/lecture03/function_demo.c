// Demonstrating functions with the program we created last week:
// Dice checker program, which checks whether the sum of the dice
// is equal to the target number. You win the game if it is. 

// Sasha Vassar, Week 3 Lecture 5


#include <stdio.h>

// 1. Scan in the two dice (scanf()))
// 2. Add the numbers together (+)
// 3. Check the sum against the target number (#define)
// 4. Output greater or less than (printf())

#define TARGET 9

int sum(int die_one, int die_two);

int main (void) {
    int die_one;
    int die_two;
    int addition;
    int scanf_return;


    printf("Enter the dice rolls (two numbers): ");
    // scanf returns an int 
    scanf_return = scanf("%d %d", &die_one, &die_two);
    
    // Since we have learnt the shorthand way of doing this...
    // Can we include our scanf() function - because it returns an int! -
    // inside our if statement?
    
    if (scanf_return != 2) {
        printf("You have not entered two numbers for the dice!\n");
        printf("The program will now exit\n");
        return 1;
    }

    addition = sum(die_one, die_two);

    if (addition > TARGET) {
        printf("The sum of the dice is greater than the target number!\n");
    } else if (addition < TARGET) {
        printf("The sum of the dice is less than the target number!\n");
    } else {
        printf("You have guessed the target number!\n");
    }

    return 0;
}


// Function to sum up two numbers:
// OUTPUT:  int
// INPUT: int, int
// Name of function: sum
//return_type name_of_function (input_type input_name, .....)
int sum(int die_one, int die_two){
    //int sum;
    //sum = die_one + die_two;
    //return sum;
    return die_one + die_two;
}
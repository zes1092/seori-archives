// Demonstrating the use of a while loop with a counter
// condition.
// Sasha Vassar Week 2, Lecture 4


// Problem: Using our dice problem from Tuesday, I want to roll five times now,
// and compare the total of all the rolls to a target number.

/* 1. Roll dice five times
        Scan in input
        Add to total
        After five times compare total to target number

*/
#define TARGET 20
#define LOOP 5

#include <stdio.h>

int main(void){

    int die_one;
    int die_two;
    int sum = 0;
    int scanf_return;

    //1.. Outside of the while loop, we need to initialise our loop
    //control variable
    int count = 0;

    while (count < LOOP) { //2. Test the loop control
        printf("Enter the dice rolls (two numbers): ");
        // scanf returns an int 
        scanf_return = scanf("%d %d", &die_one, &die_two);
        printf("Scanf() has returned: %d\n", scanf_return);

        if (scanf_return != 2) {
            printf("You have not entered two numbers for the dice!\nThe program will now exit\n");
            return 1;
        }
        sum = sum + die_one + die_two;
        //3. Update the loop control (right at the end, before you close your loop)
        count = count + 1;
    } 
    
    if (sum > TARGET) {
        printf("The sum of the dice is greater than the target number!\n");
    } else if (sum < TARGET) {
        printf("The sum of the dice is less than the target number!\n");
    } else {
        printf("You have guessed the target number!\n");
    }

    return 0;
}
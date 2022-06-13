// Demonstrating the use of a while loop with a
// condition.
// Sasha Vassar Week 2, Lecture 4

/*
Using a while loop allows us to repeat certain pieces of 
code. 

//1. Initialise loop control variable
    while (condition) { //2. Test the condition         
                         against the loop control variable

//3. Update loop control variable (last statement of while loop
}

*/

#include <stdio.h>

// Problem: I want to read in some scores and keep adding them together 
// while the sum of the scores is less than 100.

int main (void) {
    
    //1. Read in some scores
    //2. Add those scores together
    //  -Keep adding until sum of scores is less than 100 
    int score;
    
    // 1. Loop control variable - check while sum is less than 100
    int sum = 0;
    
    while (sum < 100) { //2. Check the condition - is sum less than 100?
        printf("Enter a score: ");
        scanf("%d", &score);
    
        //3. Update the loop control variable
        sum = sum + score; //120
    }
    
    printf("The final sum is %d\n", sum);

    return 0;
}
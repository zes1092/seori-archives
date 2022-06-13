// Demonstrating the use of a while loop with a sentinel
// condition.
// Sasha Vassar Week 2, Lecture 4

// Problem: I want to read in some scores until a negative number has been 
// entered, and I want to only sum together the odd scores. 

#include <stdio.h>

int main(void){

    int score;
    int sum = 0;
    //1. Initialise the loop control (sentinel)
    int endloop_flag = 0; // Sentinel - switch the flag to different position when negative number read

    while (endloop_flag == 0){ //2. test the loop control 
        printf("Please enter a score to add to the sum: ");
        scanf("%d", &score);

        // Is the number that we have read positive or negative?
        if (score >= 0) {
            //Check is it an odd number?
            if (score % 2 != 0) { // score % 2 == 1
                sum = sum + score;
                printf("The sum is now %d\n", sum);
            }          
        } else {
            endloop_flag = 1;
        }

        // sum together the odd scores only

    }
    printf("The final sum of all the scores is %d\n", sum);
    return 0;
}
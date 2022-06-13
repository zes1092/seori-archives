#include <stdio.h>

int main(void) {
    char upper_letter;
    char lower_letter;
    int scanf_return;

    printf("Please enter an upper case letter: ");
    scanf_return = scanf(" %c", &upper_letter);
    printf("Scanf() returned %d\n", scanf_return);

    if (scanf_return != 1) {
        printf("No input was taken in, the program will now exit\n");
        return 1;
    }
    if (upper_letter >= 'A' && upper_letter <= 'Z') {
        lower_letter = upper_letter - 'A' + 'a';
        printf("The lower case letter is %c\n", lower_letter);
    } else {
        printf("YOu did not enter a capital letter\n");
         // return // Dice checker program, which checks whether the sum of the dice
// is equal to the target number. You win the game if it is. 

// Sasha Vassar, Week 2 Lecture 3


#include <stdio.h>

// Problem: A user rolls two dice and tell us the number on each of
// the rolled die. Our program will add the die numbers together and
// check them against a target number that only the program knows. 
// It will then report back whether the total of the dice was higher,
// equal or lower than the secret number.


// 1. Scan in the two dice (scanf()))
// 2. Add the numbers together (+)
// 3. Check the sum against the target number (#define)
// 4. Output greater or less than (printf())

#define TARGET 9

int main (void) {
    int die_one;
    int die_two;
    int sum = 0;
    int scanf_return;


    printf("Enter the dice rolls (two numbers): ");
    // scanf returns an int 
    scanf_return = scanf("%d %d", &die_one, &die_two);
    printf("Scanf() has returned: %d\n", scanf_return);

    if (scanf_return != 2) {
        printf("You have not entered two numbers for the dice!\nThe program will now exit\n");
        return 1;
    }

    sum = die_one + die_two;

    if (sum > TARGET) {
        printf("The sum of the dice is greater than the target number!\n");
    } else if (sum < TARGET) {
        printf("The sum of the dice is less than the target number!\n");
    } else {
        printf("You have guessed the target number!\n");
    }

    return 0;
}1 - Program finished running but with some problems
        return 1;
    }
   
    //Program finished running with no problems 
    return 0;
}
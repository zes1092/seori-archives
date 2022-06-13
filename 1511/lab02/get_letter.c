// get_letter
// get_letter.c
// 
// This program was written by Ze Sheng (z5421872)
// on 28/02/2022
// 
// A program that reads in a character and an integer, then returns the index of the text.  

#include <stdio.h> 

int main (void) { 
    int index; 
    char letter;
    char sol;

    printf("Uppercase: ");
    scanf("%c", &letter); 
    
    if ((letter != 'y') && (letter != 'n')) { 
        printf("You need to enter 'y' or 'n'\n"); 
        printf("Exiting the program with error code 1\n"); 
        return 1;
    } 

    printf("Index: "); 
    scanf("%d", &index); 

    if ((index >= 1) && (index <= 26)) {
        if (letter == 'y') { 
            sol = index - 1 + 'a'; 
        } else { 
            sol = index - 1 + 'A'; 
        }
        printf("The letter is %c\n", sol);
    } else {
        printf("You need to enter a number between 1 and 26 inclusive\n"); 
        printf("Exiting the program with error code 2\n"); 
        return 1; 
    } 
    return 0; 
} 
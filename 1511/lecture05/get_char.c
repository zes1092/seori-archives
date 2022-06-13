// This program demonstrates the use of getchar() and putchar()

// Sasha Vassar Week 5 Lecture 9


#include <stdio.h>

//This is the library that contains a lot of the character functions
#include <ctype.h>

int main (void) {

    // Declare a variable int called character
    char character;
    
    printf("Enter your name as an example of getchar() and press Enter: ");
    //Use the getchar() function to read one character at a time
    //Remember that this function will take char when a new line is entered
    character = getchar();
    
    //TODO: Keep taking in stuff, until EOF is read
    //When you press Ctrl+D to signal EOF (end of file) - the while loop will
    //be exited
    while (character != EOF) {
         //printf("The character is %c\n", character);   
        
        //Using the function putchar to show output one character at a time
          putchar(character);
          printf("\n");
        //Get the next character from the buffer
          character = getchar();  
    }
    return 0;
}
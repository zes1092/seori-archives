// This program demonstrates the use of the different character functions
// that are available for you to use when you manipulate characters
// We will demo: getchar(), putchar(), isupper(), tolower() and the use of EOF

// Sasha Vassar Week 5 Lecture 9


#include <stdio.h>

//This is the library that contains a lot of the character functions
#include <ctype.h>

int main (void) {

//Declare a variable int called character
    char character;
    
    printf("Enter your name as an example of getchar() and press Enter: ");
    //Use the getchar() function to read one character at a time
    //Remember that this function will take char when a new line is entered
    
    character = getchar();
    //Keep taking in stuff, until EOF is read
    //When you press Ctrl+D to signal EOF (end of file) - the while loop will
    //be exited
    while (character != '\n') {
        printf("You entered the character: ");
        //Using the function putchar to show output one character at a time
        putchar(character);
        printf("\n");
        //TODO: Check if the character is an upper case letter by using the function
        //isupper() found in <ctype.h> standard library
        // to convert, use the function tolower() also found
        // in <ctype.h> library
        if (isupper(character)) {
            character = tolower(character);
            printf("Your new character %c\n", character);
        }
        
        //Get the next character from the buffer
        character = getchar();
       
    }
    return 0;
}
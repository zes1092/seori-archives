// This function demonstrates the use of the function fgets() to read in a 
// string of input (a whole line). And how to stop reading in on Ctrl+D being 
// pressed (fgets() uses the keyword NULL to indicate this)

// This program will then demonstrate the use of some string functions to help
// you manipulate anything to do with strings. You can find these functions
// in the standard library <string.h>. The functions we will demonstrate here
// are: 
// strcpy (copy a string from one array to another - destination/source), 
// strlen(find length of a string - doesn't include \0), and 
// strcmp (compare two strings, return 0 if they are the same)

// Sasha Vassar Week 5 Lecture 9

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 10

int main (void) {

    //1. Declare an array, where you will place the string
    char array[MAX_LENGTH];
    
    printf("Type in a string to echo: ");
    //fgets(array, MAX_LENGTH, stdin); 
    //printf("The echo of the typed word in string is: %s\n", array);
    //fputs(array, stdout);
    //printf("\n");
    //2. Read a string into the array until Ctrl+D is pressed,
    //   which is indicated by NULL keyword
    while (fgets(array, MAX_LENGTH, stdin) != NULL) {
        printf ("The string is: \n");
        printf("%s", array);
        // Let's manipulate our string! 
        // TODO: Find the length of the string:
        int length = strlen("Bonjour");
        printf("The length is %d\n", length);
        // TODO: Copy something into the string and print out new string:
        strcpy(array, "Boo");
        printf("The new array string: %s\n", array);
        
        // TODO: Compare string to another string
        int compare_string1 = strcmp("Hello", "Hello");
        printf("The two strings are the same? %d\n", compare_string1);
        
        
        printf("Type in a string to echo: ");
    }  
    return 0;
}
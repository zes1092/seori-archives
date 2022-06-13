// Add two numbers together, but in an array.

#include <stdio.h>

int main(void) {

    int char1 = getchar();
    int char2 = getchar();
    while (char1 != EOF && char2 != EOF) {
        if (char1 < char2) putchar(char1);
        else putchar(char2);
        
        char1 = getchar();
        char2 = getchar();
    }

    putchar('\n');
}
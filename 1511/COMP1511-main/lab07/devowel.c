// devowel 
// devowel.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 30/03/2022
//
// Program reads characters from its input and writes the same 
// characters to its output, except to lower case vowels

#include <stdio.h>

#include <ctype.h>

char is_vowel(char character);

int main(void) { 
    int character; 
    character = getchar(); 

    while (character != EOF) { 
        if 
        (character != 'a' && 
        character != 'e' && 
        character != 'i' &&
        character != 'o' && 
        character != 'u') 
        {
            putchar(character);
        } 
        character = getchar();  
    }

    return 0; 
}



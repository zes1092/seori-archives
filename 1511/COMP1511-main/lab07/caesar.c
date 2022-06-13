// caesar 
// caesar.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 30/03/2022
//
// Program reads cahracters from input and writes the 
// character to its output encrypted with a Caesar cipher. 

#define ALPHABET_SIZE 26 

#include <stdio.h> 

int encrypt(int shift, int character);

int main(void) { 
    int shift; 
    scanf("%d", &shift); 

    char arr[ALPHABET_SIZE];
    fgets(arr, ALPHABET_SIZE, stdin); 
    // negative shifts converted to equivalent postive shift 
    if (shift < 0) { 
        shift = ALPHABET_SIZE + (shift % ALPHABET_SIZE); 
    }

    int character; 
    character = getchar(); 
    while (character != EOF) { 
        int encrypted; 
        encrypted = encrypt(shift, character);
        putchar(encrypted); 
        c
    }

    return 0; 
}

// encrypt letters with a caesar cipher 
// characters other than letters are return unchanged 

int encrypt(int shift, int character) { 
    // handle upper case and lower case letters separately 
    if (character >= 'A' && character <= 'Z') { 
        return ('A' + (character - 'A' + shift) % ALPHABET_SIZE); 
    } else if (character >= 'a' && character <= 'z') { 
        return ('a' + (character - 'a' + shift) % ALPHABET_SIZE); 
    } else { 
        return character; 
    }
}

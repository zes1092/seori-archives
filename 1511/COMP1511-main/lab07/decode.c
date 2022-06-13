// decode 
// decode.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 30/03/2022
//
// Program reads characters from its input and writes the 
// characters to its output decrypted with a Substitution cipher.

#include <stdio.h>
#include <string.h> 

#define ALPHABET_SIZE 27

int decrypt(int character, char mapping[ALPHABET_SIZE]);
void inverse_mapping(char mapping[ALPHABET_SIZE], char inverse_mapping[ALPHABET_SIZE]);

int main(void) { 
    printf("Enter mapping: \n"); 
    char cipher[ALPHABET_SIZE]; 
    fgets(cipher, ALPHABET_SIZE, stdin); 
    char newline; 
    scanf("%c", &newline); 

    printf("Enter text:\n"); 

    char text[ALPHABET_SIZE] = {0};
    inverse_mapping(cipher, text); 

    int character = getchar(); 
    while (character != EOF) { 
        int decrypted = decrypt(character, text); 
        putchar(decrypted); 
        character = getchar();
    }
    
    return 0; 
}

// decrypts the function 
int decrypt(int character, char mapping[ALPHABET_SIZE]) { 
    if (character >= 'A' && character <= 'Z') { 
        return mapping[character - 'A'] - 'a' + 'A'; 
    } else if (character >= 'a' && character <= 'z') { 
        return mapping[character - 'a']; 
    } else { 
        return character; 
    } 
}

// inverse the mapping 
void inverse_mapping(char mapping[ALPHABET_SIZE], char inverse_mapping[ALPHABET_SIZE]) { 
    int i = 0; 
    while (i < ALPHABET_SIZE) { 
        int character = mapping[i]; 
        if (character >= 'a' && character <= 'z') {
            inverse_mapping[character - 'a'] = 'a' + i; 
        }
        i++; 
    }
}
// Exam Practice Question 5
// prac_q5.c
//
// This program was written by Ze Sheng (z5421872)
// on 22/04/2022
//
// Program prints out the unique amount of letters given two strings. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 256 

int count_char(char *str1, char *str2); 
void string_to_lower(char *str); 
int lowercase(int character); 
void remove_white_spaces(char *str); 
void remove_all(char * str, const char toRemove, int index); 
void remove_duplicates(char * str); 

int main(void) { 
    char str1[MAX]; 
    fgets(str1, MAX, stdin); 
    string_to_lower(str1);
    remove_white_spaces(str1); 
    remove_duplicates(str1); 
    
    char str2[MAX];
    fgets(str2, MAX, stdin); 
    string_to_lower(str2);
    remove_white_spaces(str2); 
    remove_duplicates(str2); 
    
    printf("\n"); 
    printf("%d\n", count_char(str1, str2)); 
}

int count_char(char *str1, char *str2) { 
    int count = 0; 
    int length1 = strlen(str1) - 1; 
    int length2 = strlen(str2) - 1;
    
    int i = 0; 
    while (i < length1) { 
        int j = 0; 
        while (j < length2) { 
            if (str1[i] == str2[j]) { 
                count++; 
            } 
            j++; 
        }
        i++; 
    }
    
    return count; 
}

void remove_duplicates(char * str) {
    int i = 0;

    while(str[i] != '\0'){
        remove_all(str, str[i], i + 1);
        i++;
    }
}

void remove_all(char * str, const char toRemove, int index) {
    int i;

    while(str[index] != '\0') {
        /* If duplicate character is found */
        if(str[index] == toRemove) {
            /* Shift all characters from current position to one place left */
            i = index;
            while(str[i] != '\0') {
                str[i] = str[i + 1];
                i++;
            }
        } else {
            index++;
        }
    }
}

void string_to_lower(char *str) { 
    int i = 0; 
    while (str[i] != '\0') { 
        str[i] = lowercase(str[i]); 
        i += 1; 
    }
}

int lowercase(int character) {
    if (character >= 'A' && character <= 'Z') {
        return character - 'A' + 'a'; 
    } else { 
        return character; 
    }
}

void remove_white_spaces(char *str) {
    int count = 0; 
    int i = 0; 
    while (str[i]) { 
        if (str[i] != ' ') { 
            str[count++] = str[i]; 
        }
        i++; 
    }
    str[count]  = '\0'; 
}
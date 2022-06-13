// String to Lower
// string_to_lower.c
//
// This program was written by Ze Sheng (z5421872)
// on 31/03/2022
//
// Function that takes a string and converts it to lower case 
//
#include <stdio.h>

#include <ctype.h>

void string_to_lower(char *string);
int lowercase(int character); 

int main(int argc, char *argv[]) {

    char str[1024] = "Hi, mY nAmE iS sPonGEbOb sQuArePanTS.";
    string_to_lower(str);
    printf("%s\n", str);

    return 0;
}

// Convert the characters in `buffer` to lower case
void string_to_lower(char *string) {
    // YOUR CODE GOES HERE!
    int i = 0; 
    while (string[i] != '\0') { 
        string[i] = lowercase(string[i]); 
        i++; 
    }
}
// need to create a new string 
// follows the ascii table 
// int i = 0; 
// while (string[i] != '\0') { 
//     putchar(tolower(word)[i]))); 
//     i++; 
//     }
// }
// the above code won't work because doesnt modify original string 
int lowercase(int character) { 
    if (character >= 'A' && character <= 'Z') { 
        return character - 'A' + 'a'; 
    } else { 
        return character; 
    }
}
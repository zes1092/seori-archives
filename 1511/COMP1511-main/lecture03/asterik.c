#include <stdio.h> 

void asterik(int number); 

int main (void) { 
    asterik(10); 
    asterik(10); 
    return 0;
}

void asterik(int number){ 
    int counter = 0; 
    while (counter < number) {
        printf("*"); 
        counter += 1; 
    }
    printf("\n"); 
}
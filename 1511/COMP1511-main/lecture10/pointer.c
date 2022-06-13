// A simple example of a pointer and how it moves about 
// & for address of
// * dereference - find what is at the address of pointer


#include <stdio.h>


int main(void) {
    int a = 5;
    int b = 10;
    int *ptr1;
    int *ptr2; 
    ptr1 = &a; 
    ptr2 = &b; 
    *ptr1 = 10; 
    ptr1 = ptr2; 
    *ptr1 = 20; 
    printf("a = %d\nb = %d\n", a, b); 
    return 0;
}
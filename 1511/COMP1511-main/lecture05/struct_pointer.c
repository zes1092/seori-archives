// This program demonstrates how to access pointers of type struct. 
// Usually we access with a . , however, when we refer to a pointer
// we access with a -> 

// Sasha Vassar, Week 7 Lecture 11

#include <stdio.h>
#include <string.h>

#define MAX 15

//1. Define struct
struct ice_cream {
    char name[MAX];
    double price;
};

int main (void) {
//2. Declare struct
    struct ice_cream my_ice_cream;
 
    //TODO: Demonstrating pointers of type struct
    //Have a pointer that points to the variable my_ice_cream of type 
    //struct ice_cream   
    struct ice_cream *my_ice_cream_ptr = & my_ice_cream; 
    
    //TODO:3. Initialise struct (access members with .)
    strcpy(my_ice_cream_ptr->name, "chocolate"); 
    my_ice_cream_ptr->price = 3; 
    //TODO: Demonstrating pointers of type struct - accessing
    //How would we initialise it using the pointer?
    //Perhaps dereference the pointer and access the member?
    printf("%s is an awesome flavour that costs $%f.\n", my_ice_cream_ptr->name, my_ice_cream_ptr->price); 
    
    return 0;
}
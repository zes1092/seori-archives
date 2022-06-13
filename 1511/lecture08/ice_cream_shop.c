// Ice cream shop

// I have decided to run an ice-cream shop (no surprises here)
// I want to create a program that can:
// 1) Take in all the flavours of ice cream that I have to offer by adding
// them to the end of the list
// 2) I want to be able to print out the flavours
// 3) I would then like to add the flavours in alphabetical order
// 4) Delete flavours as we finish them. 

// Starter code is provided


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

// Root structure - starting up a shop, which will have flavours
struct shop {
    struct ice_cream *flavour; //where I store the head of my list shop->flavour
};

// Structure of ice cream has the quantity and the flavour name
struct ice_cream {
    int number;
    char name[MAX_LENGTH];
    struct ice_cream *next_flavour;
};

// Helper functions
struct shop *setup_shop();
struct ice_cream *create_ice_cream(char name[MAX_LENGTH], int number);
void append_ice_cream(struct shop *shop, char name[MAX_LENGTH], int number);
void print_ice_creams(struct shop *shop);

void insert_alphabetical(struct shop *shop, char name[MAX_LENGTH], int number);

// Function to delete 
// Inputs and Outputs of a delete node function?
// Input: head of the list, and the value I want to delete
// Output: head of the list
struct shop *delete_flavour(struct shop *shop, char name[MAX_LENGTH]);

// The main function starts here and this is where the magic happens
int main (void) {
    struct shop *shop = setup_shop();
    
    append_ice_cream(shop, "Cheese", 3);
    append_ice_cream(shop, "Dulce", 5);
    append_ice_cream(shop, "Matcha", 2);
    
    insert_alphabetical(shop, "Vanilla", 5);
    
    print_ice_creams(shop);
    
    delete_flavour(shop, "Vanilla");
    print_ice_creams(shop);
    
    return 0;

}

// Function to setup the root shop structure
// Inputs and outputs?
// Outputs - struct shop 
// Inputs - nothing - setting up the shop
struct shop *setup_shop() {
    struct shop *shop = malloc(sizeof(struct shop));
    shop->flavour = NULL;
    return shop;    
}

// Helper function that creates a new ice-cream
// Inputs and Outputs?
// Output - will be the new_ice cream node 
// Inputs - name of the ice_cream and number available
struct ice_cream *create_ice_cream(char name[MAX_LENGTH], int number){
    struct ice_cream *new_ice_cream = malloc(sizeof(struct ice_cream));
    new_ice_cream->number = number;
    strcpy(new_ice_cream->name, name);
    new_ice_cream->next_flavour = NULL;
   
    return new_ice_cream;
}

// Helper function to add ice_cream flavour to the back of the list
// Inputs and Outputs?
void append_ice_cream(struct shop *shop, char name[MAX_LENGTH], int number){
    struct ice_cream *new_ice_cream = create_ice_cream(name, number);
    
    struct ice_cream *current = shop->flavour;
    // what if it is an empty list, and the it is going to be the head
    if (current == NULL) { // this means it is an empty list
        shop->flavour = new_ice_cream;
        // I don't want to do anything else after I added this node to an 
        // empty listm so I return back on line below
        return;
    }
    
    // If I am appending to the end of the list 
    while (current->next_flavour != NULL) {
        current = current->next_flavour;
    }
    // current->next = NULL - that we are standing on the very last node of the list
    current->next_flavour = new_ice_cream;
    
    return;
}    

// Helper function to print the ice_cream flavours out
// Inputs and Outputs?
void print_ice_creams(struct shop *shop) {
    printf("Ice-cream flavours are: \n");
    struct ice_cream *current = shop->flavour;
    while (current != NULL) {
        printf("%s %d\n", current->name, current->number);
        current = current->next_flavour;
    } //when i exit this, i will have current = NULL
}

// Function to insert flavours in alphabetical order
// Inputs and Outputs?

// We can use the strcmp function to do this:
// strcmp returns 0 if the two strings are identical
// >0 if the first non-matching character is greater than that of the second string
// <0 if the first non-matching character is less than that of the second string
// Example: Macadamia and Chocolate (M>C so >0)
// Example: Chocolate and Macadamia (C<M so <0) 
// Hazelnut > Dulce
// Hazelnut < 
void insert_alphabetical(struct shop *shop, char name[MAX_LENGTH], int number) {
    struct ice_cream *current = shop->flavour;
    struct ice_cream *new_ice_cream = create_ice_cream(name, number);
    
    while (current->next_flavour != NULL && strcmp(name, current->next_flavour->name) > 0){
        current = current->next_flavour;
    }
    new_ice_cream->next_flavour = current->next_flavour;
    current->next_flavour = new_ice_cream;
}

struct shop *delete_flavour(struct shop *shop, char name[MAX_LENGTH]) {

// Empty list
// Head of the list (where there are no more items? or other items)
// Tail of the list
// Middle normal delete
    struct ice_cream *current = shop->flavour;
    
    // Empty list
    if (current == NULL) {
        return NULL;
    } else if (strcmp(name, current->name) == 0) {
        struct ice_cream *new_head = current->next_flavour;
        free(current);
        shop->flavour = new_head;
        return shop;
    }
    
    while (strcmp(name, current->next_flavour->name) != 0) {
        current = current->next_flavour;
    }
    
    struct ice_cream *new_next = current->next_flavour->next_flavour;
    free(current->next_flavour);
    current->next_flavour = new_next;
    
    return shop;
    
}





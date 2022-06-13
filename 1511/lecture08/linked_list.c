// This program introduced the linked list data structure
// We are able to insert at the end of a linked list with 
// create_node function and are able to traverse the list
// with the print function

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    // pointer to a node, called next_address
    // int *number_ptr = pointer to an int
    struct node *next_address; 
};

struct node *create_node(int data, struct node *address);
void printer(struct node *head);
struct node *insert_end(struct node *head);
//struct node *insert_middle(struct node *head, int data);
// Deleting a node - what do you think you would need to give a function to 
// delete a node, and what would be the output?
struct node *delete_node(struct node *head, int data);

int main(void) {

    struct node *head_ptr; 
    
    head_ptr = create_node(5, NULL);
    head_ptr = create_node(3, head_ptr);
    head_ptr = create_node(1, head_ptr);
    
    insert_end(head_ptr);
    //insert_middle(head_ptr, 4); 
    
    //printer(head_ptr);
    struct node *new_head = delete_node(head_ptr, 1);
    printer(new_head);
    //printer(head_ptr);
    
    return 0;
}

// This function creates a new node
// Output: a pointer to the node that was created
// Input: data and memory address for the node that you want to create
struct node *create_node(int data, struct node *address){
    // returns a pointer to the memory address it created
    // you give malloc the number of bytes that you want
    
    struct node *new_node = malloc(sizeof(struct node));
    
    // (*new_node).data is the same as new_node->data
    new_node->data = data;
    new_node->next_address = address;
    
    return new_node;

}

// Function to insert a node at the end of the list!
// Output: struct node * 
// Input: struct node *head 
struct node *insert_end(struct node *head){
    struct node *current = head;
    
    while (current->next_address != NULL){
        current = current->next_address;
    }
    // at this point current->next = NULL and that means you are sitting on 
    // the last node
    struct node *new_node = create_node(10, NULL);
    current->next_address = new_node;
    return head;
}

/*// Function to insert between two nodes of the list
// Output: head
// Input: head 
struct node *insert_middle(struct node *head, int data){
    struct node *current = head;
    
    struct node *new_node = create_node(data, NULL);
    
    while (current != NULL) {
        if (current->data <= data && current->next_address->data >= data) {
            new_node->next_address = current->next_address;
            current->next_address = new_node;       
        }
        current = current->next_address;
    }
    return head;
}

*/


// FUnction that traverses the list and prints out the data stored in the nodes
// Output: void (printing stuff out to terminal, not returning anything back)
// Input: head of the list (so that we know where to start)
void printer(struct node *head){
    struct node *current = head;
    while (current != NULL){
        printf("%d\n", current->data);
        current = current->next_address;
    }
}

// FUnction to delete nodes
// Input: head of the list in which to delete, and item to delete
// Output: the new head of the list

struct node *delete_node(struct node *head, int data){

    //create a current pointer variable to traverse the list with
    struct node *current = head;
    // if there is no nodes in the list (the list is empty)
    // this is a common edge case that everyone forgets!
    if (current == NULL){
        return NULL; 
    } else if (current->data == data) {
        struct node *new_head = current->next_address;
        free (current);
        return new_head;
    }
    
    // delete in the middle othe list
    while (current->next_address->data != data && current->next_address->next_address != NULL) {
        current = current->next_address; 
    }
    // When I come out of the while loop either current->next->data = data that I 
    // want to delete - this means that I have stopped at the node before the
    // node that I want to delete
    // or current->next->next == NULL 
    if (current->next_address->data == data) {    
        struct node *new_next = current->next_address->next_address;
        // free the node to be deleted here
        free(current->next_address);
        // point the current node to the new node as the next one
        current->next_address = new_next;
    }
    return head;

}



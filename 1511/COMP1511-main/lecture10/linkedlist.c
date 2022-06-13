// This program introduced the linked list data structure
// We are able to insert at the end of a linked list with 
// create_node function and are able to traverse the list
// with the print function

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next; 
};

struct node *create_node(int data, struct node *address);
void printer(struct node *head);
struct node *insert_end(struct node *head);
struct node *delete_node(struct node *head, int data);
int find_range(struct node *head);
int find_smallest(struct node *head);
int find_largest(struct node *head);
struct node *insert_middle(int value, struct node *head);
int count_divisible(int value, struct node *head);
struct node *delete_first_divisible(int value, struct node *head);


int main(void) {

    struct node *head_ptr; 
    
    head_ptr = create_node(5, NULL);
    head_ptr = create_node(3, head_ptr);
    head_ptr = create_node(1, head_ptr);
    
    insert_end(head_ptr);
        
    //struct node *new_head = delete_node(head_ptr, 1);
    printer(head_ptr);
    printf("The range of the list is %d\n", find_range(head_ptr));
    
    struct node *new_head = insert_middle(13, head_ptr);
    printer(new_head);
    
    printf("The number of items divisible by 5 is %d\n", count_divisible(5, head_ptr));
    
    new_head = delete_first_divisible(10, head_ptr);
    printer(new_head);
    
    
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
    new_node->next = address;
    
    return new_node;

}

// Function to insert a node at the end of the list!
// Output: struct node * 
// Input: struct node *head 
struct node *insert_end(struct node *head){
    struct node *current = head;
    
    while (current->next != NULL){
        current = current->next;
    }
    // at this point current->next = NULL and that means you are sitting on 
    // the last node
    struct node *new_node = create_node(10, NULL);
    current->next = new_node;
    return head;
}


// FUnction that traverses the list and prints out the data stored in the nodes
// Output: void (printing stuff out to terminal, not returning anything back)
// Input: head of the list (so that we know where to start)
void printer(struct node *head){
    struct node *current = head;
    while (current != NULL){
        printf("%d\n", current->data);
        current = current->next;
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
        struct node *new_head = current->next;
        free (current);
        return new_head;
    }
    
    // delete in the middle othe list
    while (current->next->data != data && current->next->next != NULL) {
        current = current->next; 
    }
    // When I come out of the while loop either current->next->data = data that I 
    // want to delete - this means that I have stopped at the node before the
    // node that I want to delete
    // or current->next->next == NULL 
    if (current->next->data == data) {    
        struct node *new_next = current->next->next;
        // free the node to be deleted here
        free(current->next);
        // point the current node to the new node as the next one
        current->next = new_next;
    }
    return head;

}

// Revision Problem 1:
// Function to find the range of a linked list 
// Find the biggest number the list, find the smallest number in the lists //Subtract those numbers
// Output: integer
// Input: head of the list where we are finding the range  
int find_range(struct node *head) {
// What happens if the list is empty????
    if (head == NULL) {
        return 0;
    }

    //otherwise let's find the range!
    int smallest = find_smallest(head);
    int largest = find_largest(head);
    
    return largest - smallest;
}

// Helper function to find smallest number in the linked list
// Output: int (smallest number)
// Input: head 
int find_smallest(struct node *head) {
    struct node *current = head;
    int smallest = current->data;
    
    while (current != NULL){
        if (current->data < smallest) {
            smallest = current->data;
        }
        current = current->next;
    } 
    return smallest;
}


// Helper function to find largest number in the linked list
// Output: int (smallest number)
// Input: head 
int find_largest(struct node *head) {
    struct node *current = head;
    int largest = current->data;
    
    while (current != NULL){
        if (current->data > largest) {
            largest = current->data;
        }
        current = current->next;
    } 
    return largest;
}


// 1, 2, 3, 10, 4, 5, 6 (insert_middle 10)
// 5 (insert_middle 5)


// Revision Problem 2:
// Insert specified value into the middle of a linked list 
// Output: head
// Input: value, head 
struct node *insert_middle(int value, struct node *head) {
    struct node *current = head;
    struct node *new_node = create_node(value, NULL);
    int count = 0;
    
    if (head == NULL) {
        new_node->next = head;
        return new_node;
    }

    while (current != NULL){
        count++;
        current = current->next;
    }
    
    int mid = count / 2;
    int insert_at = 0;
    
    struct node *insert_after = head;
    while (insert_at < mid - 1) {
        insert_after = insert_after->next;
        insert_at++;
    }
    new_node->next = insert_after->next;
    insert_after->next = new_node;
    
    return head;    
}



// Revision Problem 3:
// Concatenate two lists together (join list 2 onto list 1)
// Output: 
// Input: 





// Revision Problem 4: 
// Count all the elements in the linked list that are divisible by a 
// specified number
// Output: int 
// Input: head of the list
int count_divisible(int value, struct node *head) {

    struct node *current = head;
    int counter = 0;
    
    while (current != NULL) {
        if (current->data % value == 0) {
            counter++;
        } 
        current = current->next;
    }
    return counter;
}



// Revision Problem 5: 
// Delete the first node in the linked list that is divisible by a 
// specified number
// Output: head
// Input: value, head
struct node *delete_first_divisible(int value, struct node *head) {
// Boundary cases
// 1. Empty list DONE
// 2. list with 1 node, and I want to delete that one node DONE
// 3. delete the head DONE
// 4. delete the tail *WHAT SHALL WE DO???*
// 5. Nothing to delete?

    // What if it is an empty list?
    if (head == NULL) {
        return NULL;
    }
    
    // Example: 3, 10, 1 (delete first that is divisible by 3)
    // Returning: 10, 1 
    // Example: 3
    // Return: NULL
    // What if I have to delete the head of the list?
    if (head->data % value == 0) {
        // I have to delete the head!
        struct node *temp = head->next;
        free(head);
        return temp;
    }

    // Example: 3, 10, 1 (delete first thing that is divisible by 5)
    // Example: 3, 2, 6, 5 (delete first thing that is divisible by 5)
    
    struct node *current = head;
    while (current->next != NULL) {
        if (current->next->data % value == 0) {
            // Yay time to delete! 
            struct node *temp = current->next->next; //this has the address of 1 now
            free(current->next); // deleted the node with 10 in it
            current->next = temp; 
        }
        current = current->next;
    }
    // WHAT HAPPENS WHEN I DELETE THE TAIL???? HOW DO I TAKE CARE OF THE TAIL NOW??? *HOMEWORK*
    
    return head;
}


















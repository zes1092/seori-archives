// Exam Practice Question 6
// prac_q6.c
//
// This program was written by Ze Sheng (z5421872)
// on 22/04/2022
//
// Program prints out the unique amount of letters given two strings. 

#include <stdio.h>
#include <stdlib.h>

struct node { 
    int data; 
    struct node *next; 
};

struct stack { 
    int length; 
    struct node *nodes; 
};

void valid_brackets(int *file_contents); 
struct stack *create_stack(); 
struct node *create_node(int data); 
void push(struct stack *stack, int data); 
int pop(struct stack *stack); 
char corresponding_closing_bracket(int opening); 

int main(void) {
    struct stack *new_stack = create_stack();  
    int check = 0; 

    int character = getchar(); 
    while (character != EOF) { 
        // if opening bracket push to the top of the stack 
        if (character == '(' || character == '[' || character == '<' || character == '{') { 
            push(new_stack, character);
            check++; 
        } else {   
            // unmatched right char case 
            if 
            ((character == ')' && new_stack->nodes == NULL) || 
            (character == ']' && new_stack->nodes == NULL) || 
            (character == '>' && new_stack->nodes == NULL) || 
            (character == '}' && new_stack->nodes == NULL)) { 
                check++;

            } else if 
            ((character == ')' && new_stack->nodes->data != '(') || 
            (character == ']' && new_stack->nodes->data != '[') || 
            (character == '>' && new_stack->nodes->data != '<') || 
            (character == '}' && new_stack->nodes->data != '{')) { 
                // ensure a match -> peek the top of the stack 
                check++; 
                break; 
            } else if 
            ((character == ')' && new_stack->nodes->data == '(') || 
            (character == ']' && new_stack->nodes->data == '[') || 
            (character == '>' && new_stack->nodes->data == '<') || 
            (character == '}' && new_stack->nodes->data == '{')) { 
                // if closing bracket of the stack matches the 
                // open bracket then pop it out of the stack 
                pop(new_stack); 
                check--;
            }
        }
        character = getchar(); 
    }

    if (check == 0) { 
        printf("Valid Sequence!\n"); 
    } else if (check > 0) {
        printf("Invalid Sequence, the correct closing sequence is:\n"); 
        struct node *curr = new_stack->nodes;
        while (curr != NULL) { 
            char close = corresponding_closing_bracket(curr->data);
            printf("%c\n", close); 
            curr = curr->next; 
        }
    }

    free(new_stack); 
    return 0; 
}

// malloc a new stack and return a point to it. 
struct stack *create_stack() { 
    struct stack *stack  = malloc(sizeof(struct stack)); 
    stack->length = 0; 
    stack->nodes = NULL; 

    return stack; 
}

// malloc a new new given the provided 'data' and return a pointer to it. 
struct node *create_node(int data) { 
    struct node *node = malloc(sizeof(struct node)); 
    node->data = data; 
    node->next = NULL; 
    
    return node; 
}

// Given a `stack`, push a new node onto it with the given `data`
void push(struct stack *stack, int data) {
    struct node *new = create_node(data);
    new->next = stack->nodes;
    stack->nodes = new;

    stack->length++;
}

// Given a `stack`, pop the top of that stack and return the data inside of it
int pop(struct stack *stack) {
    if (stack->length == 0) {
        return 0;
    }

    struct node *popped = stack->nodes;
    stack->nodes = stack->nodes->next;
    stack->length--;

    int return_data = popped->data;
    free(popped);

    return return_data;
}

char corresponding_closing_bracket(int opening) {
    if (opening == '(') {
        return ')';
    }
    if (opening == '[') {
        return ']';
    }
    if (opening == '{') {
        return '}';
    }
    if (opening == '<') {
        return '>';
    }
    return '\0'; 
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item {
    int data;
    struct item *next;
};

struct item *new_item(int data);

struct item *push_item(struct item *stack, int data) {

    struct item *new = new_item(data);
    new->next = stack;

    return new;
}

struct item *new_item(int data) {
    struct item *new = malloc(sizeof(struct item));
    new->data = data;
    new->next = NULL;

    return new;
}

/**
 * This is a simple main function that you can use to test your 
 * push_item function.
 * It will not be marked - only your push_item function will be marked.
 *
 * Note: The autotest does not call this main function!
 * It calls your push_item function directly.
 * Any changes that you make to this main function will not affect the autotests.
 */
int main(void) {

    printf("Enter items: ");
    struct item *stack = NULL;
    int data;
    while (scanf("%d", &data) == 1) {
        stack = push_item(stack, data);
    }

    printf("The stack was: ");
    struct item *curr = stack;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
    
    return 0;
}
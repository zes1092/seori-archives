#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

// return the average of the values in a linked list
double average(struct node *head) {

    // PUT YOUR CODE HERE (change the next line!)
    struct node *curr = head; 
    double avg = 0; 
    int length = 0; 

    if (curr == NULL) { 
        return avg; 
    }

    while (curr != NULL) { 
        avg += curr->data; 
        length++; 
        curr = curr->next; 
    }

    avg = avg / length; 

    return avg;

}

double average(struct node *head);
struct node *read_list(void);

// DO NOT CHANGE THIS MAIN FUNCTION

int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = read_list();

    double result = average(head);
    printf("%.1lf\n", result);

    return 0;
}


// DO NOT CHANGE THIS FUNCTION

// Read linked list from standard input,
// stopping when -1 is read
struct node *read_list(void) {
    struct node *head = NULL;
    struct node *tail = NULL;
    int num;
    while (scanf("%d", &num) == 1 && num != -1) {
        struct node *new = malloc(sizeof(struct node));
        new->data = num;
        new->next = NULL;
        if (head == NULL) {
            head = new;
            tail = new;
        } else {
            tail->next = new;
            tail = new;
        }
    }
    return head;
}

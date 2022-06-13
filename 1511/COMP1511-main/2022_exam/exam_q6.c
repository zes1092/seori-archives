#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_LEN 4096

struct card {
    int num;
    struct card *next;
};

struct card *deck_read(int player_num);
void print_deck(struct card *deck); 

void print(struct card *player1, struct card *player2, struct card *pile); 

struct card *pop(struct card *head); 
struct card *push(int value, struct card *head); 

int main(void) {
    struct card *player1 = deck_read(1);
    struct card *player2 = deck_read(2);

    struct card *pile = NULL;
    while (player1 != NULL && player2 != NULL) {
        pile = push(player1->num, pile);
        player1 = pop(player1);

        if (pile->next != NULL) {
            if (pile->num == pile->next->num) {
                printf("Snap! Matched card %d \n", pile->num);
                print(player1, player2, pile); 
                return 0;
            }
        }

        if (player1 != NULL) {
            pile = push(player2->num, pile);
            player2 = pop(player2);
            if (pile->next != NULL) {
                if (pile->num == pile->next->num) {
                    printf("Snap! Matched card %d \n", pile->num);
                    print(player1, player2, pile); 
                    return 0;

                }
            }
        }
    }

    if (player1 == NULL && player2 != NULL) {
        printf("Player 2 has won! \n");
        print(player1, player2, pile); 
    } else {
        printf("Player 1 has won! \n");
        print(player1, player2, pile); 
    }

    return 0;

}

void print(struct card *player1, struct card *player2, struct card *pile) { 
    printf("Player 1's deck: ");
    print_deck(player1);

    printf("Player 2's deck: ");
    print_deck(player2);

    printf("Pile: ");
    print_deck(pile);
}

struct card *push(int value, struct card *head) {
    struct card *new_card = malloc(sizeof(struct card)); 
    new_card->num = value; 
    new_card->next = head; 
    return new_card; 
}

struct card *pop(struct card *head) {
    struct card *current = head;

    if (head == NULL) { 
        return NULL; 
    }

    struct card *new_head = current->next;
    if (current == head) {
        free(current);
    }
    return new_head;
}

void print_deck(struct card *deck) {
    while (deck != NULL) {
        printf("%d -> ", deck->num);
        deck = deck->next;
    }
    printf("X\n");
}

// Function to create a deck for the specified player.
// Returns a pointer to the top card in the deck.
struct card *deck_read(int player_num) {
    int num;
    printf("Enter Player %d's deck values:\n", player_num);
    struct card *head = NULL;
    struct card *tail = NULL;
    while (scanf("%d", &num) == 1) {
        if (num == -1) break;
        struct card *new_card = malloc(sizeof(struct card));
        new_card->num = num;
        new_card->next = NULL;
        if (head == NULL) {
            head = tail = new_card;
        } else {
            tail = tail->next = new_card;
        }
    }
    return head;
}

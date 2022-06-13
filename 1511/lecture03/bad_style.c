// This is an example of very bad style... Let's see if we can clean it right up. 
// How is everyone feeling, dizzy yet?

// Sasha Vassar Week 3, Lecture 5

// 1. What do you think this program does?
// 2. Can you see any mistakes?
// 3. How do we fix *this*?

#include <stdio.h>

#define BUDGET 10


struct ice_cream {
    double price;
    int scoop;
    char flavour;
};


int main(void){

    struct ice_cream bill;
    int total = 0;
    char loop = 'y';
    int scan;   

    bill.price = 1.25;
        
    while (loop == 'y') {
        printf("Starting .........\n");
        printf("What flavour do you want and how many scoops of that flavour: ");
        scan = scanf("%c %d", &bill.flavour, &bill.scoop);
        
        if (scan != 2) {
            printf("Error, you did not put in flavour and scoops\n");
            return 1;
        }
        
        total = total + (bill.price * bill.scoop);
        
        if (total > BUDGET){
            printf("You do not have enough money to buy this much ice-cream.\n");
            return 0;
        } else {
            printf("Yay! You have enough to get some ice-cream\n");
        }
          
        printf("Would you like to try ordering more ice-cream (y/n)? "); 
        scanf(" %c", &loop);
    }
    return 0;
}
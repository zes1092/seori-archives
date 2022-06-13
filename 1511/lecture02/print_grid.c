// A while inside a while (tick tock)
// Demonstrating how you can put a while inside a while to print out a 
// grid of numbers
// Sasha Vassar Week 2, Lecture 4

/* Problem: Print out a grid of numbers that looks like this: 

1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5

So we are printing out a square... 
Each row sees the numbers increase by one, and then we go back to 1 when we start in the next row.

Can you print out one row of numbers?
*/

#include <stdio.h>

int main(void){

    // 1 2 3 4 5
    // 1
    // 2
    int size;
    printf("What size grid would you like to print: ");
    scanf("%d", &size);
    // control variable - initialise variable
    int row = 1;
   
    while (row <= size) {
       int col = 1;
       while (col <= size) {
           printf("%d ", col);
           col = col + 1;
       }
       printf("\n");
       row = row + 1;
    }
    
    return 0;
}
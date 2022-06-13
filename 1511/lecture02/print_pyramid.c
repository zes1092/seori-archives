// A while inside a while (tick tock)
// Demonstrating how you can put a while inside a while to print out a 
// pyramid of numbers
// Sasha Vassar Week 2, Lecture 4


/* Problem: Print out a grid of numbers that looks like this: 
                    row     col   no_of_rows
1                    1      1           1
1 2                  2      2           2  
1 2 3                3       3     
1 2 3 4              4      4        4   
1 2 3 4 5              

*/

#include <stdio.h>

int main(void){
    int size;
    printf("What size grid would you like to print: ");
    scanf("%d", &size);
    
    // control variable - initialise variable
    
    
    int row = 1;
   
    while (row <= size) {
       int col = 1;
       while (col <= row) {
           printf("%d ", col);
           col = col + 1;
       }
       printf("\n");
       row = row + 1;
    }
    
    return 0;
}
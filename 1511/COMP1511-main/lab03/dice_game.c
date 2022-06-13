// dice_game
// dice_game.c
// 
// This program was written by Ze Sheng (z5421872)
// on 02/03/2022
// 
// A program that reads 10 integers 
// from the user representing dice rolls on a 6-sided dice.


#include <stdio.h>

int main(void) {
    int num;
    int sum = 0; 

    printf("Enter numbers: ");

    int count = 1; 
    int last_1 = 0; 
    while (count <= 10) { 
        scanf("%d", &num);  
        if (num < 1 || num > 6) { 
            return 1;    
        } 
        if (last_1 == 1) { 
            if (num == 1) { 
                last_1 = 1; 
                num = num * 2; 
                last_1 = 0;
            } else {
                num = num * 2; 
                last_1 = 0; 
            }
        }
        if (num == 1) { 
            last_1 = 1; 
        }
        sum += num; 
        count += 1; 
    }
    printf("The sum of dice rolls is %d.\n", sum);
    return 0; 
}





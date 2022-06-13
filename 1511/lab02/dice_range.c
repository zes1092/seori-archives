// dice_range
// dice_range.c
// 
// This program was written by Ze Sheng (z5421872)
// on 27/02/2022
//
// A program that shows the dice range of a set of dice

#include <stdio.h> 

int main(void) { 
    int dicesize; 
    int numberdice; 
    int highest; 
    double average; 

    printf("Enter the number of sides on your dice: ");
    scanf("%d", &dicesize);
    printf("Enter the number of dice being rolled: "); 
    scanf("%d", &numberdice); 

    highest = numberdice * dicesize; 
    average = (numberdice + highest) / 2.0;
    
    if (dicesize <= 0 || highest <= 0) { 
        printf("These dice will not produce a range.\n");
    } else { 
        printf("Your dice range is %d to %d.\n", numberdice, highest);
        printf("The average value is %lf\n", average);
    }
    return 0;
}
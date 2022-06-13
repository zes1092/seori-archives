// is_leap_year
// is_leap_year.c
// 
// This program was written by Ze Sheng (z5421872)
// on 27/02/2022
//
// A program that reads a year and then prints whether that year is a leap year.

#include <stdio.h>

int main (void) { 
    int year;
    
    printf("Enter year: "); 
    scanf("%d", &year); 

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))  { 
        printf("%d is a leap year.\n", year); 
    } else { 
        printf("%d is not a leap year.\n", year);   
    }
    return 0;
}
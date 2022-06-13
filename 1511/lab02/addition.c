// addition 
// addition.c
// 
// This program was written by Ze Sheng (z5421872)
// on 27/02/2022
// 
// A program to calculuate the number of students and tutors in a classroom. 

#include <stdio.h>

int main(void) {
    int students; 
    int tutors;    
    printf("Please enter the number of students and tutors: ");
    scanf("%d %d", &students, &tutors); 
    int sum = students + tutors; 
    printf("%d + %d = %d\n", students, tutors, sum);
    return 0;
}

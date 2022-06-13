// word_addition.c
// word_addition.c
// 
// This program was written by Ze Sheng (z5421872)
// on 27/02/2022
// 
// A program that add two numbers and print them out, as words. 

#include <stdio.h> 

int main(void) { 
    int num1; 
    int num2;
    printf("Please enter two integers"); 
    scanf("%d %d", &num1, &num2);
    int sum = num1 + num2; 

    if (num1 >= -10 && num1 <= 10) { 
        if (num1 < 0) { 
            printf("negative ");
            num1 *= -1; 
        }
        if (num1 == 0) {
            printf("zero"); 
        }   
        if (num1 == 1) { 
            printf("one"); 
        }
        if (num1 == 2) {
            printf("two"); 
        }
        if (num1 == 3) { 
            printf("three"); 
        }
        if (num1 == 4) {
            printf("four"); 
        }   
        if (num1 == 5) { 
            printf("five"); 
        }
        if (num1 == 6) {
            printf("six"); 
        }
        if (num1 == 7) { 
            printf("seven"); 
        }
        if (num1 == 8) {
            printf("eight"); 
        }   
        if (num1 == 9) { 
            printf("nine"); 
        }
        if (num1 == 10) {
            printf("ten"); 
        }
    } else { 
        printf("%d", num1); 
    } 
    printf(" + "); 

    if (num2 >= -10 && num2 <= 10) { 
        if (num2 < 0) { 
            printf("negative ");
            num1 *= -1; 
        }
        if (num2 == 0) {
            printf("zero"); 
        }   
        if (num2 == 1) { 
            printf("one"); 
        }
        if (num2 == 2) {
            printf("two"); 
        }
        if (num2 == 3) { 
            printf("three"); 
        }
        if (num2 == 4) {
            printf("four"); 
        }   
        if (num2 == 5) { 
            printf("five"); 
        }
        if (num2 == 6) {
            printf("six"); 
        }
        if (num2 == 7) { 
            printf("seven"); 
        }
        if (num2 == 8) {
            printf("eight"); 
        }   
        if (num2 == 9) { 
            printf("nine"); 
        }
        if (num2 == 10) {
            printf("ten"); 
        }
    } else { 
        printf("%d", num2);
    }
    printf(" = ")
     if (sum >= -10 && sum <= 10) { 
        if (sum < 0) { 
            printf("negative ");
            sum *= -1; 
        }
        if (sum == 0) {
            printf("zero\n"); 
        }   
        if (sum == 1) { 
            printf("one\n"); 
        }
        if (sum == 2) {
            printf("two\n"); 
        }
        if (sum == 3) { 
            printf("three\n"); 
         }
        if (sum == 4) {
            printf("four\n"); 
        }   
        if (sum == 5) { 
            printf("five\n"); 
        }
        if (sum == 6) {
            printf("six\n"); 
        }
        if (sum == 7) { 
            printf("seven\n"); 
        }
        if (sum == 8) {
            printf("eight\n"); 
        }   
        if (sum == 9) { 
            printf("nine\n"); 
        }
        if (sum == 10) {
            printf("ten\n"); 
        }
    } else { 
        printf("%d\n", sum);
    }
    return 0; 
}
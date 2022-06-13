// cs_calculator 
// cs_calculator.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 7/03/2022
//
// Program which scans in instructions and prints output

#include <stdio.h>

int main(void) {
    char program;
    int number1;
    int number2;
    printf("Enter instruction: ");
    while (scanf(" %c", &program) != EOF) {
        int result = 1;
        if (program == 's') {
            scanf("%d", &number1);
            number1 *= number1;
            result = number1;
        } else if (program == 'p') {
            scanf("%d %d", &number1, &number2);
            while (number2 != 0) {
                result *= number1;
                number2--;
            }
        }
        printf("%d\n", result);
        printf("Enter instruction: ");
    }

    return 0;
}

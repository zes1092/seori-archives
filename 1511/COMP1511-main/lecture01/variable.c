// This program shows how to declare
// and initialise a variable

// Sasha Vassar, 22T1 Week 1 Variables


// 1. Declare the variable - I am letting C know that I need a variable, 
// I have to let it know what type of variable I also want!
// 2. Initialise the variable - give it some initial value



#include <stdio.h>

// Define some constants!

#define PI 3.1415
#define MEANING_OF_LIFE 42
#define FIRST_LETTER 'A'

int main(void){
    
    /*
    // 1. Declare an int (data type variable_name;)
    int age;
    // 2. Initialise it
    age = 42;
    // Declare and initialise on the same line!
    
    int age = 42;  
    printf("The age is %d\n", age); 
    
    age = 19;
    int second_age = 35;
    int third_age = 12;
    
    // %d is used to output an integer
    // %lf is used for a double
    // %c is used for a character
    
    printf("The age is %d, second age %d, third %d\n", age, second_age, third_age); 
    
    
    // 1. Declare 
    // double decimal;
    // 2. Initialise
    // decimal = 3.4;
    
    double decimal = 3.42;
    
    printf("The decimal is %.2lf\n", decimal);
    
    // Declare and initialise a char variable 
    char character = 's';
    // output to terminal - printf
    printf("The character is %c\n", character);
    
    // input from terminal scanf()
    
    int integer;
    printf("Please enter a number: ");
    scanf("%d", &integer);
    
    printf("The number you entered is %d\n", integer);
    
    char character;
    printf("Enter a character please: ");
    scanf("%c", &character);
    
    printf("The character you entered is: %c\n", character);
    */
    int number1 = 50;
    int number2 = 42;
    
    // < > ==  <=  >= != 
    // = assign a value
    // == checks equivalence
    
    // 42 > 11 ? TRUE 
    if (MEANING_OF_LIFE > number2) { //FALSE
        printf("%d is greater than %d\n", MEANING_OF_LIFE, number2);    
    } else if (MEANING_OF_LIFE < number2) { //FALSE
        printf("%d is less than %d\n", MEANING_OF_LIFE, number2); 
    } else if (MEANING_OF_LIFE == number2) { //TRUE
        printf("%d is equal to %d\n", MEANING_OF_LIFE, number2);
    }
    
    
    
    
    /*
    int remainder;
    // 42 % 5 = 2
    remainder = MEANING_OF_LIFE % number1;
    
    printf("The result is %d\n", remainder);
    */    
    return 0;
}










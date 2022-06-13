#include <stdio.h>
#include <stdlib.h>


int main(void) {
    int my_value = 0;
    int *ptr_one = NULL;
    int *ptr_two = NULL;
    ptr_two = &my_value;

    if (ptr_two != NULL) {
        *ptr_two = 42;
    }

    printf("%d\n", my_value);

    return 0;
    // Which of a, b, c, d or e are the longest string
    // at this point in the code?

}
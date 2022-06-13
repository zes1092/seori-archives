// Program to scan in three integers and print out the middle one.

#include <stdio.h>

struct numbers {
    int first;
    int second;
    int third;
};

int main(void) {
    // DO NOT CHANGE CODE BELOW HERE
    struct numbers nums;
    printf("Enter integer: ");
    scanf("%d", &nums.first);

    printf("Enter integer: ");
    scanf("%d", &nums.second);

    printf("Enter integer: ");
    scanf("%d", &nums.third);
    // DO NOT CHANGE CODE ABOVE HERE

    // ADD CODE BELOW HERE
    int middle = nums.first;
    if (nums.first > nums.second) {
        // third second first
        if (nums.second > nums.third) {
            middle = nums.second;
        // second third first
        } else if (nums.first > nums.third) {
            middle = nums.third;
        }
    } else {
        // first second third
        if (nums.third > nums.second) {
            middle = nums.second;
        // first third second
        } else if (nums.third > nums.first) {
            middle = nums.third;
        }
    }

    printf("Middle: %d\n", middle);
    return 0;
}
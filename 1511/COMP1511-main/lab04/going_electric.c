// going_electric 
// going_electric.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 7/03/2022
//
// Program which scans in a serires of stations providing an output of how many stops 

#include <stdio.h> 

#define MAX 10000

void array_print(int arr[MAX], int final);

int main(void) {
    
    int stat[MAX] = {};
    int input;
    int counter = 0;

    while (scanf("%d", &input) != EOF) {
        stat[counter] = input;
        counter++;
    }
    counter -= 1;

    int stop = 0;
    int stops_counter = 0;
    while (stop < counter + 1) {
        int current_stop_charge = stat[stop];
        stop += current_stop_charge; 
        if (current_stop_charge != 0) {
            stops_counter++;
        } else {
            if (stop == counter) {
                stop = counter + 1;
            } else if (stat[stop - 1] == 1 || stat[stop - 1] == 0) {
                stops_counter = 0;
                stop = counter + 1;
            } else {
                stop--;
                stops_counter++;
            }
        }
    }
    printf("%d \n" , stops_counter);
    return 0;
}

void array_print(int arr[MAX], int final) {
    int i = 0;
    while (i <= final) {
        printf("%d \n", arr[i]);
        i++;
    }

}
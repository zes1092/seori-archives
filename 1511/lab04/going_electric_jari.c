// This program was written by Syed Jari Haider (z5424919)
// This program reverses an array


#include <stdio.h>
#define MAX_STATIONS 1000

void array_print(int arr[MAX_STATIONS], int final_idx);

int main(void) {
    
    int stations[MAX_STATIONS] = {};
    int input;
    int input_counter = 0;

    while (scanf("%d", &input) != EOF) {
        stations[input_counter] = input;
        input_counter++;
    }
    input_counter--;

    //lets begin the journey
    int stop = 0;
    int stops_counter = 0;
    while (stop < input_counter + 1) {
        int current_stop_charge = stations[stop];
        stop += current_stop_charge; //e.g if charge is 2, we can skip one stop
        if (current_stop_charge != 0) {
            stops_counter++;
        } else {
            if (stop == input_counter) {
                stop = input_counter + 1;
            } else if (stations[stop - 1] == 1 || stations[stop - 1] == 0) {
                stops_counter = 0;
                stop = input_counter + 1;
            } else {
                stop--;
                stops_counter++;
            }
        }
    }
    printf("%d \n" , stops_counter);
    return 0;
}

void array_print(int arr[MAX_STATIONS], int final_idx) {
    int i = 0;
    while (i <= final_idx) {
        printf("%d \n", arr[i]);
        i++;
    }

}
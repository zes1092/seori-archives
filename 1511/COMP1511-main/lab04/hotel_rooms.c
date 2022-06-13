// hotel_rooms 
// hotel_rooms.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 7/03/2022
//
// Program which scans in a certain number of hotel rooms and prints their details

#include <stdio.h>

#define MAX_ROOMS 50

struct hotel_room {
    // TODO: fill this in with the details of each hotel room
    int room_number; 
    double price;
};

// Prints the room in the correct format when given the room_number
// and price of it.
void print_room(int room_number, double price);

int main(void) {
    struct hotel_room arr[MAX_ROOMS]; 
    int number; 
    printf("How many rooms? ");
    // TODO: scan in how many rooms in the hotel
    scanf("%d", &number); 
    printf("Enter hotel rooms:\n");
    // TODO: scan in the details of each hotel room
    int i = 0; 
    while (i < number) { 
        scanf("%d %lf", &arr[i].room_number, &arr[i].price);
        i += 1; 
    }
    printf("Room List:\n");
    // TODO: print all the rooms scanned in
    int j = 0;
    while (j < number) {
        print_room(arr[j].room_number, arr[j].price);
        j++;
    }

    return 0;
}

// Prints the room in the correct format when given the room_number
// and price of it.
//
// Takes in:
// - `room_number` -- The hotel room's room number.
// - `price` -- How much the hotel room costs.
//
// Returns: nothing.
void print_room(int room_number, double price) {

    printf("Room %d @ $%.2lf\n", room_number, price);

    return;
}
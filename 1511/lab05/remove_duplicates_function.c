// remove_duplicates_function 
// remove_duplicates_function.c 
// 
// This program was written by Ze Sheng (z5421872)
// on 15/03/2022
//
// Program removes duplicate elements from an array, 
// by copying the non-duplicate values to a second array

int remove_duplicates(int length, int source[length], int destination[length]) {
    int destination_upto = 0;
    int source_upto = 0;
    while (source_upto < length) {
        int duplicate = 0;
        int check = 0;
        while (check < source_upto) {
            if (source[source_upto] == source[check]) {
                duplicate = 1;
                break;
            }
            check += 1;
        }
        if (!duplicate) {
            destination[destination_upto] = source[source_upto];
            destination_upto += 1;
        }
        source_upto += 1;
    }
    return destination_upto;
}

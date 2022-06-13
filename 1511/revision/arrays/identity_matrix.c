// identity_matrix.c
// Given a 2D array (or matrix), find the 
// Corresponding identity matrix
// Liz Willer 
// March 2020
#include <stdio.h>
#include <stdlib.h>


void make_identity(int size, int matrix[size][size]);
void print_matrix(int size, int matrix[size][size]);

int main(void){
    int array2[2][2] = {{3, 1}, {4, 1}};
    int array3[3][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}};
    int array10[10][10] = {{0}};

    make_identity(2, array2);
    make_identity(3, array3);
    make_identity(10, array10);
    
    print_matrix(2, array2);
    printf("\n");
    print_matrix(3, array3);
    printf("\n");
    print_matrix(10, array10);

    return 0;
}

void make_identity(int size, int matrix[size][size]) {
    int i = 0;
    while (i < size){
        int j = 0;
        while (j < size){
            matrix[i][j] = 0;
            j++;
        }
        i++;
    }

    i = 0;
    while (i < size) {
        matrix[i][i] = 1;
        i++;
    }

}

void print_matrix(int size, int matrix[size][size]) {
    int i = 0;
    while (i < size){
        int j = 0;
        while (j < size){
            printf("%d ", matrix[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }

}
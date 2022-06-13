// It is time to hunt for ice cream. This program 
// should show my efforts exploring one particular 
// section, which is sized 10x10. The game ends if I come
// to the same place as I have already been to or press 
// Ctrl + D
//
// Starter code 
//
// Written by Sasha Vassar March, 2021

/*

What is an EOF?
End of File - may return an -1 when used scanf, #defined EOF 
while (scanf("%d", &number) != EOF) 
this means, that you will keep scanning in until Ctrl+D 

*/



#include <stdio.h>

// The dimensions of the section grid I will explore
#define N_ROWS 10
#define N_COLS 10

// Struct for player to hold the character name, and 
// my position on the map 
struct player {
    char name;
    int pos_row;
    int pos_col;
};

// Helper Function: Print out the section map as a 2D grid
void print_section(int section[N_ROWS][N_COLS] struct player sasha);


int main(void) {

    int section[N_ROWS][N_COLS] = {0};
    struct player sasha;
    // Initialise the coordinates of where Sasha 
    // is standing when she enters the section
    sasha.name = 'S';
    sasha.pos_row = 9;
    sasha.pos_col = 9;
    
    print_section(section, sasha);

    // Scan in a command
    // NOTE: direction will be '<', '>', '^' or 'v'.
    char direction;
    
    printf("Where would sasha like to go? [<,>,^,v] ");
    
    // scanf("%d %d", &number, &number2) return 2
    // scanf("%d", &number) and typed in char return 0
    // scanf can return the number of things that were scanned in and placed into variables but also it can do one more special thing! It can return EOF (Ctrl+D)
    int scanf_return = scanf(" %c", &direction);
    
    while (scanf_return != EOF) {
        //This next line changes the grid element to 
        // 1 where I have been already
        section[sasha.pos_row][sasha.pos_col] = 1;
        if (direction == '<') {
            sasha.pos_col--;
        } else if (direction == '>') {
            sasha.pos_col++;
        } else if (direction == '^') {
            sasha.pos_row--;
        } else if (direction == 'v') {
            sasha.pos_row++;
        }
        
        // Check for boundary of the grid
        if (sasha.pos_row < 0) {
            sasha.pos_row = 0;
        } else if (sasha.pos_col < 0) {
            sasha.pos_col = 0;
        } else if (sasha.pos_row >= N_ROWS){
            sasha.pos_row = N_ROWS - 1;
        } else if (sasha.pos_col >= N_COLS){
            sasha.pos_col = N_COLS - 1;
        }
        
        print_section(section, sasha);
        printf("Where would sasha like to go? [<,>,^,v] ");
    }
    
    return 0;
}


// Prints the section map, by printing the integer value 
// stored in each element of the 2-dimensional section array. 
// Should also allow to print where each player is currently
// standing
void print_section(int section[N_ROWS][N_COLS], struct player sasha) {
    int row = 0;
    while (row < N_ROWS) {
        int col = 0;
        while (col < N_COLS) {
            //TODO: will need to print out the character 
            // for me based on where I am currently standing
            if (sasha.pos_row == row && sasha.pos_col == col) {
                printf("%c ", sasha.name);
            } else {
                printf("%d ", section[row][col]); 
            }
            col++;
        }  
        printf("\n");
        row++;
    }
}
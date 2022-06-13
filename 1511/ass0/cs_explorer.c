// CS Explorer
// cs_explorer.c
//
// This program was written by Ze Sheng (z5421872)
// on 28/03/2022
//
// Version 1.0.0 (2022-03-08): Assignment Released.
//
// Program which creates a 2D exploration game by moving around the map. 

#include <stdio.h>

// Additional libraries here


// Provided constants 
#define SIZE 8
#define PLAYER_STARTING_ROW (SIZE - 1)
#define PLAYER_STARTING_COL 0
#define EMPTY_POINTS 0
#define EMPTY_TYPE 'E'
#define PLAYER_TYPE 'P'
#define MONSTER_TYPE 'M'
#define HEALING_TYPE 'H'
#define BOULDER_TYPE 'B'

// Your constants here
#define FILL_TYPE '-'
#define FULL_HEALTH 10
#define UP 'u'
#define DOWN 'd'
#define LEFT 'l'
#define RIGHT 'r'
#define GAME_WON 0
#define GAME_LOST 1

// Provided struct
struct location {
    char occupier;
    int points;
};

// Your structs here

// Provided functions use for game setup
// You do not need to use these functions yourself.
void init_map(struct location map[SIZE][SIZE]);
void place_player_on_starting_location(struct location map[SIZE][SIZE]);

// You will need to use these functions for stage 1.
void print_cheat_map(struct location map[SIZE][SIZE]);
void print_game_play_map(struct location map[SIZE][SIZE]);

// Your functions prototypes here
void basic_movement(char movement, int *player_row, int *player_col);
void clamping(int *player_row, int *player_col);
void boulder_boundary(char movement, int *ptr_row, int *ptr_col, struct location map[SIZE][SIZE]);
void game_won(int *ptr_count, struct location map[SIZE][SIZE]);

int main(void) {

    struct location map[SIZE][SIZE];
    init_map(map);

    printf("Welcome Explorer!!\n");
    printf("How many game pieces are on the map?\n");
    
    // TODO: Add code to scan in the number of game pieces here.
    int pieces; 
    scanf("%d", &pieces); 
  
    // TODO: Add code to scan in the details of each game piece and place them
    //       on the map
    printf("Enter the details of game pieces:\n"); 
    int points;
    int row;
    int col;
    // Stage 1.1 Game Setup
    int i = 0; 
    while (i < pieces) {
        scanf("%d %d %d", &points, &row, &col);
        // Could have implemented an if function for better style. 
        if (points >= -9 && points <= 9 
            && row < 8 && row >= 0  
            && col < 8 && col >= 0) { 
            if (points < 0)  {
                map[row][col].points = points;
                map[row][col].occupier = MONSTER_TYPE;   
            } else if (points == 0) {
                map[row][col].points = points;
                map[row][col].occupier = BOULDER_TYPE;
            } else { 
                map[row][col].points = points;
                map[row][col].occupier = HEALING_TYPE;
            }
            
            if (row == PLAYER_STARTING_ROW && col == PLAYER_STARTING_COL) { 
                map[row][col].points = points;
                map[row][col].occupier = PLAYER_TYPE;
            }
        }
        i++; 
    }
    // After the game pieces have been added to the map print out the map.
    print_game_play_map(map);
    printf("\nEXPLORE!\n");
    printf("Enter command: ");

    // TODO: keep scanning in commands from the user until the user presses
    // ctrl + d

    char command;
    int player_row = PLAYER_STARTING_ROW; 
    int player_col = PLAYER_STARTING_COL;
    int health = FULL_HEALTH;

    int *ptr_row = &player_row; 
    int *ptr_col = &player_col;

    while (scanf(" %c", &command) != EOF) { 
        // Stage 1.2 Printing Cheat Map
        if (command == 'c') { 
            print_cheat_map(map);
        } 
        // Stage 1.3 Quit Game
        if (command == 'q') { 
            printf("Exiting Program!\n"); 
            return 1; 
        } 
        //Stage 2.1 Basic Movement 
        if (command == 'm') {
            char movement;
            scanf(" %c", &movement);
            // Stage 2.1 Function 
            map[player_row][player_col].occupier = FILL_TYPE;
            basic_movement(movement, ptr_row, ptr_col); 
            clamping(ptr_row, ptr_col);
            boulder_boundary(movement, ptr_row, ptr_col, map);
            // Stage 2.3, 2.4 Player Health  
            health += map[player_row][player_col].points;
        }
        // Stage 2.2, 2.3, 2.4 Player Health 
        if (command == 'h') { 
            printf("Your player is at (%d, %d) with a health of %d.\n", player_row, 
            player_col, health);
        }
        // Stage 2.5 Points in a Square
        if (command == 's') { 
            int row_square; 
            int col_square; 
            int size_square;
            char type_square; 
            int potion_health = 0; 
            int monster_health = 0; 

            // intialises the top left corner of the basic counting square 
            scanf("%d %d %d  %c", &row_square, &col_square, &size_square, &type_square); 
            int *ptr_row_square = &row_square; 
            int *ptr_col_square = &col_square; 
            clamping(ptr_row_square, ptr_col_square);
            
            int new_row_square = row_square + size_square;  
            int new_col_square = col_square + size_square;
            int *ptr_new_row_square = &new_row_square; 
            int *ptr_new_col_square = &new_col_square; 
            clamping(ptr_new_row_square, ptr_new_col_square); 

            int col_square_count = col_square; 
            while (row_square < new_row_square) { 
                col_square = col_square_count; 
                while (col_square < new_col_square) { 
                    if (map[row_square][col_square].occupier == MONSTER_TYPE) { 
                        monster_health += map[row_square][col_square].points;
                    } else if (map[row_square][col_square].occupier == HEALING_TYPE) { 
                        potion_health += map[row_square][col_square].points;
                    }
                    col_square++;
                }
                row_square++;
            }
            if (type_square == MONSTER_TYPE) {
                printf("Monsters in this section could apply %d health points.\n", monster_health);
                monster_health = 0; 
            } else if (type_square == HEALING_TYPE) {
                printf("Healing Potions in this section could apply %d health points.\n", potion_health);
                potion_health = 0;
            }
        }
        // Stage 3.1 Game Won
        int game_count = 0; 
        int *ptr_game_count = &game_count; 
        game_won(ptr_game_count, map);
        if (game_count == 0) {
            printf("GAME WON!\n");
            return 1;
        } 
        // Stage 3.2 Game Lost 
        if (health <= 0) {
            printf("GAME LOST!\n");
            return 1; 
        } 
        if (command == 'b') {
            int boulder_row; 
            int boulder_col; 
            scanf("%d %d", &boulder_row, &boulder_col);

        }
        if (map[player_row + 1][player_col].occupier == BOULDER_TYPE && 
        map[player_row - 1][player_col].occupier == BOULDER_TYPE && 
        map[player_row][player_col + 1].occupier == BOULDER_TYPE && 
        map[player_row][player_col - 1].occupier == BOULDER_TYPE) {
            printf("GAME LOST!\n"); 
            return 1; 
        } 
        
        print_game_play_map(map);
        printf("Enter command: ");
    }

    return 0;
}


////////////////////////////////////////////////////////////////////////////////
///////////////////////////// ADDITIONAL FUNCTIONS /////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// TODO: you may need to add additional functions here

// Stage 3.2 Game Lost Function 
// The player is surrounded by boulders - and therefore can’t move. 

// game won functin (stage 3.1)
// After every command, the program should check if the game has been won. 
// The game is won if there are no more monsters on the map.
void game_won(int *ptr_count, struct location map[SIZE][SIZE]) {
    int row_count = 0;
    while (row_count < SIZE) { 
        int col_count = 0;
        while (col_count < SIZE) { 
            if (map[row_count][col_count].occupier == MONSTER_TYPE) { 
                *ptr_count += 1; 
            }
            col_count++;
        }
        row_count++; 
    }
}
// basic_movement function (stage 2.1)
// Player ('P') moves around the map confined ihe map boundaries. 
// A player cannot move to where a boulder is placed.  
// To move right is 'r'. To move left is 'l'
// To move down is 'd'. To move up is 'u'
void basic_movement(char movement, int *ptr_row, int *ptr_col) {
    if (movement == LEFT) { 
        *ptr_col = *ptr_col - 1; 
    } else if (movement == RIGHT) { 
        *ptr_col = *ptr_col + 1; 
    } else if (movement == UP) { 
        *ptr_row = *ptr_row - 1; 
    } else if (movement == DOWN) { 
        *ptr_row = *ptr_row + 1; 
    }
}

// clamping function (stage 2.1) 
// A player cannot move outside the bounds of the map. 
// If a movement command would result in the player moving off the map
// that command should be ignored.
void clamping(int *ptr_row, int *ptr_col) {
    // Check for boundary of the grid 
    if (*ptr_row < 0) { 
        *ptr_row = 0; 
    } else if (*ptr_row >= SIZE) { 
        *ptr_row = (SIZE - 1); 
    }
    if (*ptr_col < 0) { 
        *ptr_col = 0;
    } else if (*ptr_col >= SIZE) { 
        *ptr_col = (SIZE - 1); 
    }
}

// boulder boundary (stage 2.1)
// A player cannot move to a location that is occupied by a boulder.
// If a movement command would result in the player moving on 
// to a boulder, that command should be ignored.
void boulder_boundary(char movement, int *ptr_row, int *ptr_col, 
struct location map[SIZE][SIZE]) {
    if (map[*ptr_row][*ptr_col].occupier == BOULDER_TYPE) {
        if (movement == LEFT) { 
            map[*ptr_row][*ptr_col].occupier = BOULDER_TYPE;
            *ptr_col = *ptr_col + 1; 
            map[*ptr_row][*ptr_col].occupier = PLAYER_TYPE;
        } else if (movement == RIGHT) { 
            map[*ptr_row][*ptr_col].occupier = BOULDER_TYPE;
            *ptr_col = *ptr_col - 1; 
            map[*ptr_row][*ptr_col].occupier = PLAYER_TYPE;
        } else if (movement == UP) { 
            map[*ptr_row][*ptr_col].occupier = BOULDER_TYPE;
            *ptr_row = *ptr_row + 1; 
            map[*ptr_row][*ptr_col].occupier = PLAYER_TYPE;
        } else if (movement == DOWN) { 
            map[*ptr_row][*ptr_col].occupier = BOULDER_TYPE;
            *ptr_row = *ptr_row - 1; 
            map[*ptr_row][*ptr_col].occupier = PLAYER_TYPE;
        }
    } else { 
        map[*ptr_row][*ptr_col].occupier = PLAYER_TYPE;
    }
}




////////////////////////////////////////////////////////////////////////////////
////////////////////////////// PROVIDED FUNCTIONS //////////////////////////////
/////////////////////////// (DO NOT EDIT BELOW HERE) ///////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Provided Function
// Initalises all elements on the map to be empty to prevent access errors.
void init_map(struct location map[SIZE][SIZE]) {
    int row = 0;
    while (row < SIZE) {
        int col = 0;
        while (col < SIZE) {
            struct location curr_loc;
            curr_loc.occupier = EMPTY_TYPE;
            curr_loc.points = EMPTY_POINTS;
            map[row][col] = curr_loc;
            col++;
        }
        row++;
    }

    place_player_on_starting_location(map);
}

// Provided Function
// Places the player in the bottom left most location.
void place_player_on_starting_location(struct location map[SIZE][SIZE]) {
    map[PLAYER_STARTING_ROW][PLAYER_STARTING_COL].occupier = PLAYER_TYPE;
}

// Provided Function
// Prints out map with alphabetic values. Monsters are represented with 'M',
// healing potions in 'H', boulders with 'B' and the player with 'P'.
void print_game_play_map(struct location map[SIZE][SIZE]) {
    printf(" -----------------\n");
    int row = 0;
    while (row < SIZE) {
        printf("| ");
        int col = 0;
        while (col < SIZE) {
            if (map[row][col].occupier == EMPTY_TYPE) {
                printf("- ");
            } else {
                printf("%c ", map[row][col].occupier);
            }
            col++;
        }
        printf("|\n");
        row++;
    }
    printf(" -----------------\n");
}

// Provided Function
// Prints out map with numerical values. Monsters are represented in red,
// healing potions in blue, boulder in green and the player in yellow.
//
// We use some functionality you have not been taught to make sure that
// colours do not appear during testing.
void print_cheat_map(struct location map[SIZE][SIZE]) {

    printf(" -----------------\n");
    int row = 0;
    while (row < SIZE) {
        printf("| ");
        int col = 0;
        while (col < SIZE) {
            if (map[row][col].occupier == PLAYER_TYPE) {
                // print the player in purple
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;35m");
                #endif
                // ----------------------------------------
                printf("%c ", PLAYER_TYPE);
            } else if (map[row][col].occupier == HEALING_TYPE) {
                // print healing potion in green
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;32m");
                #endif
                // ----------------------------------------
                printf("%d ", map[row][col].points);
            } else if (map[row][col].occupier == MONSTER_TYPE) {
                // print monsters in red
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;31m");
                #endif
                // ----------------------------------------
                printf("%d ", -map[row][col].points);
            } else if (map[row][col].occupier == BOULDER_TYPE) {
                // print boulder in blue
                // ----------------------------------------
                // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
                #ifndef NO_COLORS
                printf("\033[1;34m");
                #endif
                // ----------------------------------------
                printf("%d ", map[row][col].points);
            } else {
                // print empty squares in the default colour
                printf("- ");
            }
            // ----------------------------------------
            // YOU DO NOT NEED TO UNDERSTAND THIS CODE.
            // reset the colour back to default
            #ifndef NO_COLORS
            printf("\033[0m");
            #endif
            // ----------------------------------------
            col++;
        }
        printf("|\n");
        row++;
    }
    printf(" -----------------\n");
}

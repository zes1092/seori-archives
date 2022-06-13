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
// stage 2 functions
int move_col(char movmement, int col);
int move_row(char movement, int row);
int clamp(int row_col);
int boulder_row(char movement, int row);
int boulder_col(char movement, int col);
void square_points(int row, int col, char type,
int new_row, int new_col, struct location map[SIZE][SIZE]); 
void print_points(char type, int monster, int potion); 

// stage 3 functions 
int game_won(struct location map[SIZE][SIZE]);
int game_lost(int row, int col, struct location map[SIZE][SIZE]); 
void rectangle_points(int start_row, int start_col, int end_row, 
int end_col, char type, struct location map[SIZE][SIZE]); 
int negative(int num); 
int small(int num1, int num2);

// stage 4 functions 
int section_points(int row, int col, int new_row,
int new_col, int hint_size, struct location map[SIZE][SIZE]); 

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
            && row < SIZE && row >= EMPTY_POINTS  
            && col < SIZE && col >= EMPTY_POINTS) { 
            if (points < EMPTY_POINTS)  {
                map[row][col].points = points;
                map[row][col].occupier = MONSTER_TYPE;   
            } else if (points == EMPTY_POINTS) {
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
            player_row = move_row(movement, player_row);
            player_col = move_col(movement, player_col); 

            if (map[player_row][player_col].occupier == BOULDER_TYPE) {
                map[player_row][player_col].occupier = BOULDER_TYPE;
                player_col = boulder_col(movement, player_col); 
                player_row = boulder_row(movement, player_row); 
                map[player_row][player_col].occupier = PLAYER_TYPE;
            } else { 
                map[player_row][player_col].occupier = PLAYER_TYPE;
            }
            // Stage 2.3, 2.4 Player Health  
            health += map[player_row][player_col].points;
        }

        // Stage 2.2, 2.3, 2.4 Player Health 
        if (command == 'h') { 
            printf("Your player is at (%d, %d) with a health of %d.\n", 
            player_row, player_col, health);
        }

        // Stage 2.5 Points in a Square
        if (command == 's') { 
            int row_square; 
            int col_square; 
            int size_square;
            char type_square; 

            // intialises the top left corner of the basic counting square 
            scanf("%d %d %d  %c", &row_square, &col_square, &size_square, &type_square); 
            row_square = clamp(row_square); 
            col_square = clamp(col_square);
            int new_row = row_square + size_square;  
            int new_col = col_square + size_square;
            new_col = clamp(new_col); 
            new_row = clamp(new_row);  
            square_points(row_square, col_square, type_square, 
            new_row, new_col, map); 
        }

        // Stage 3.3 Falling Boulders 
        if (command == 'b') { 
            int bldr_row; 
            int bldr_col;
            scanf("%d %d", &bldr_row, &bldr_col);
            bldr_row = clamp(bldr_row); 
            bldr_col = clamp(bldr_col); 
            if (bldr_row == player_row && bldr_col == player_col) {
                print_game_play_map(map);  
                printf("GAME LOST!\n");
                return 1;
            }
            map[bldr_row][bldr_col].points = EMPTY_POINTS;
            map[bldr_row][bldr_col].occupier = BOULDER_TYPE;
        }

        // Stage 3.4 Counting Points in a Rectangle 
        if (command == 'r') {
            int start_row; 
            int start_col; 
            int end_row; 
            int end_col; 
            char type_rect; 
            scanf("%d %d %d %d  %c", &start_row, &start_col, 
            &end_row, &end_col, &type_rect); 
            start_row = clamp(start_row); 
            start_col = clamp(start_col); 
            end_row = clamp(end_row); 
            end_col = clamp(end_col);
            rectangle_points(start_row, start_col, end_row, 
            end_col, type_rect, map); 

        }
        
        // Stage 4.1 Next Step Hint 
        if (command == 'n') { 
            int hint_size; 
            scanf("%d", &hint_size);
            // left up 
            printf("The recommended move is: "); 
            int new_hint_size = hint_size * hint_size;

            int left_up_row = player_row - 1; 
            left_up_row = clamp(left_up_row); 
            int left_up_col = player_col - 1; 
            left_up_col = clamp(left_up_col); 
            int top_left_row = left_up_row - hint_size; 
            top_left_row = clamp(top_left_row); 
            int top_left_col = left_up_col - hint_size; 
            top_left_col = clamp(top_left_col); 
            double left_up = section_points(left_up_row, left_up_col, top_left_row, 
            top_left_col, new_hint_size, map); 

            int right_up_row = player_row - 1; 
            right_up_row = clamp(right_up_row); 
            int right_up_col = player_col + 1; 
            right_up_col = clamp(right_up_col); 
            int top_right_row = right_up_row + new_hint_size; 
            top_right_row = clamp(top_right_row); 
            int top_right_col = right_up_col + new_hint_size; 
            top_right_col = clamp(top_right_col); 
            double right_up = section_points(right_up_row, right_up_col, top_right_row, 
            top_right_col, new_hint_size, map);

            int left_down_row = player_row + 1; 
            left_down_row = clamp(left_down_row); 
            int left_down_col = player_col - 1; 
            left_down_col = clamp(left_down_col); 
            int down_left_row = left_down_row + new_hint_size; 
            down_left_row = clamp(down_left_row); 
            int down_left_col = left_down_col + new_hint_size;
            down_left_col = clamp(down_left_col);  
            double left_down = section_points(left_down_row, left_down_col, down_left_row, 
            down_left_col, new_hint_size, map);

            int right_down_row = player_row + 1; 
            right_down_row = clamp(right_down_row); 
            int right_down_col = player_col + 1; 
            right_down_col = clamp(right_down_col); 
            int down_right_row = right_down_row + new_hint_size; 
            down_right_row = clamp(down_right_row); 
            int down_right_col = right_down_col + new_hint_size; 
            down_right_col = clamp(down_right_col);
            double right_down = section_points(right_down_row, right_down_col, 
            down_right_row, down_right_col, new_hint_size, map);
            
            if ((left_down == left_up) && (right_up == right_down) && 
            (right_down == left_up)) { 
                printf("Left Up\n"); 
            } else if ((left_up < left_down) && (left_up < right_down) &&
            (left_up < right_up)) { 
                printf("Left Up\n"); 
            } else if ((left_down < left_up) && (left_down < right_down) &&
            (left_down < right_up)) { 
                printf("Left Down\n"); 
            } else if ((right_up < left_down) && (right_up < right_down) &&
            (right_up < left_up)) { 
                printf("Right Up\n"); 
            } else if ((right_down < left_down) && (right_down < right_up) &&
            (right_down < right_up)) { 
                printf("Right Down\n"); 
            }
        }
        // Stage 3.2 Game Lost 
        int game_count = 0; 
        game_count = game_lost(player_row, player_col, map);
        if (health <= 0 || game_count == GAME_LOST) {
            print_game_play_map(map);  
            printf("GAME LOST!\n");
            return 1; 
        }
        // Stage 3.1 Game Won 
        game_count = 0; 
        game_count = game_won(map); 
        if (game_count == GAME_WON) {
            print_game_play_map(map);
            printf("GAME WON!\n");
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
// Stage 4.1 Next Step Hint Function 
// Calculate the safest area around the player. 
// Also calculates a "danger quotient" for four areas that are all size x size.

int section_points(int row, int col, int new_row,
int new_col, int new_hint_size, struct location map[SIZE][SIZE]) 
{
    int monster_health = 0; 
    int potion_health = 0; 
    int boulder_count = 0; 
    int col_count = col; 
    while (row < new_row) { 
        col = col_count; 
        while (col < new_col) { 
            if (map[row][col].occupier == MONSTER_TYPE) { 
                monster_health += map[row][col].points;
            } else if (map[row][col].occupier == HEALING_TYPE) { 
                potion_health += map[row][col].points;
            } else if (map[row][col].occupier == BOULDER_TYPE) { 
                boulder_count++; 
            }
            col++;
        }
        row++;
    }
    monster_health *= -1; 
    int numerator = monster_health - potion_health;
    int denominator = new_hint_size - boulder_count; 
    double danger_quotient = numerator / denominator;
    return danger_quotient; 
}

// Stage 3.4 Counting Points in a Rectangle Function 
// Intialises the top left corner and calculates the damage points 
// from monster or potions 
// Uses square_points function in Stage 2.5 
void rectangle_points(int start_row, int start_col, int end_row, 
int end_col, char type, struct location map[SIZE][SIZE]) 
{
    // Calculates the smallest value from two given values
    // This occurs when two coordinates are rotated
    int small_row = small(start_row, end_row);
    int small_col = small(start_col, end_col); 
    int row_length = start_row - end_row; 
    row_length = negative(row_length); 
    int col_length = start_col - end_col; 
    col_length = negative(col_length); 
    int row = row_length + small_row + 1; 
    int col = col_length + small_col + 1;
    square_points(small_row, small_col, type, row, col, map);
}

// Stage 3.4 Negative Multiplier Function 
// Function used in rectangle_points 
// To find the absolute length of either row or col 
int negative(int num) { 
    if (num < 0) { 
        num *= -1; 
    }
    return num; 
}

// Stage 3.4 Small Number Function 
// Function used in rectangle_points 
// To find the smallest number between two numbers. 
int small(int num1, int num2) { 
    int small;
    if (num1 < num2) {
        small = num1; 
    } else if (num1 == num2) { 
        small = num1; 
    } else {
        small = num2;
    }
    return small; 
}

// Stage 2.5 Square Points function
// Counts all the damage points or all the healing points 
// within a specified square on the map.
// Clamps all variables so it does not go over the boundary.
void square_points(int row, int col, char type,
int new_row, int new_col, struct location map[SIZE][SIZE]) 
{
    int potion_health = 0; 
    int monster_health = 0; 
    int col_count = col; 
    while (row < new_row) { 
        col = col_count; 
        while (col < new_col) { 
            if (map[row][col].occupier == MONSTER_TYPE) { 
                monster_health += map[row][col].points;
            } else if (map[row][col].occupier == HEALING_TYPE) { 
                potion_health += map[row][col].points;
            }
            col++;
        }
        row++;
    }
    print_points(type, monster_health, potion_health); 
}

// Stage 2.5 Print Points Function 
// Specifies whether to count the damage points (from monsters) 
// or healing points (from potions). 
void print_points(char type, int monster, int potion) {
    if (type == MONSTER_TYPE) {
        printf("Monsters in this section could apply %d health points.\n", monster);
    } else if (type == HEALING_TYPE) {
        printf("Healing Potions in this section could apply %d health points.\n", potion);
    }
}

// Stage 3.2 Game Lost Function 
// The player is surrounded by boulders or the boundary 
// and therefore can’t move
int game_lost(int row, int col, struct location map[SIZE][SIZE]) { 
    int game_count = 0; 
    if 
    (map[clamp(row + 1) ][col].occupier != HEALING_TYPE &&
    map[clamp(row - 1) ][col].occupier != HEALING_TYPE &&
    map[row][clamp(col + 1) ].occupier != HEALING_TYPE &&
    map[row][clamp(col - 1) ].occupier != HEALING_TYPE &&
    map[clamp(row + 1) ][col].occupier != MONSTER_TYPE &&
    map[clamp(row - 1) ][col].occupier != MONSTER_TYPE &&
    map[row][clamp(col + 1) ].occupier != MONSTER_TYPE &&
    map[row][clamp(col - 1) ].occupier != MONSTER_TYPE &&
    map[clamp(row + 1) ][col].occupier != EMPTY_TYPE &&
    map[clamp(row - 1) ][col].occupier != EMPTY_TYPE &&
    map[row][clamp(col + 1) ].occupier != EMPTY_TYPE &&
    map[row][clamp(col - 1) ].occupier != EMPTY_TYPE &&
    map[clamp(row + 1) ][col].occupier == BOULDER_TYPE &&
    map[clamp(row - 1) ][col].occupier == BOULDER_TYPE &&
    map[row][clamp(col + 1) ].occupier == BOULDER_TYPE &&
    map[row][clamp(col - 1) ].occupier == BOULDER_TYPE)
    {
        game_count++; 
    } 
    return game_count;
}

// Stage 3.1 Game Won Function
// After every command, the program should check if the game has been won. 
// The game is won if there are no more monsters on the map.
int game_won(struct location map[SIZE][SIZE]) {
    int game_count = 0; 
    int row_count = 0;
    while (row_count < SIZE) { 
        int col_count = 0;
        while (col_count < SIZE) { 
            if (map[row_count][col_count].occupier == MONSTER_TYPE) { 
                game_count++; 
            }
            col_count++;
        }
        row_count++; 
    }
    return game_count; 
}


// Stage 2.1 Move Column Function
// Player ('P') moves around the map confined ihe map boundaries. 
// A player cannot move to where a boulder is placed.  
// To move right is 'r'. To move left is 'l'
int move_col(char movement, int col) {
    if (movement == LEFT) { 
        col -= 1; 
    } else if (movement == RIGHT) { 
        col += 1; 
    }
    int col_clamp = clamp(col);
    return col_clamp; 
}

// stage 2.1 Move Row Function
// Player ('P') moves around the map confined ihe map boundaries. 
// A player cannot move to where a boulder is placed. 
// To move down is 'd'. To move up is 'u'
int move_row(char movement, int row) { 
    if (movement == UP) { 
        row -= 1; 
    } else if (movement == DOWN) { 
        row += 1; 
    }
    int row_clamp = clamp(row);
    return row_clamp;
}

// Stage 2.1 Clamp Values function 
// A player cannot move outside the bounds of the map. If a movement 
// would result in the player moving off the map that command should be ignored.
int clamp(int row_col) {
    // Check for boundary of the grid 
    if (row_col < 0) { 
        row_col = 0; 
    } else if (row_col >= SIZE) { 
        row_col = (SIZE - 1); 
    }
    return row_col;
}

// Stage 2.1 Boulder Col Clamp Function
// A player cannot move to a location that is occupied by a boulder.
// If a movement command moves on to a boulder, that command should be ignored.
int boulder_col(char movement, int col) {
    if (movement == LEFT) { 
        col += 1; 
    } else if (movement == RIGHT) { 
        col -= 1;
    }
    return col;
}

// Stage 2.1 Boulder Row Clamp Function
// A player cannot move to a location that is occupied by a boulder.
// If a movement command moves on to a boulder, that command should be ignored.
int boulder_row(char movement, int row) {
    if (movement == UP) { 
        row += 1; 
    } else if (movement == DOWN) { 
        row -= 1; 
    }
    return row;
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

// CS Airline
// cs_airline.c
//
// This program was written by Ze Sheng (z5421872)
// on 22/04/2022
//
// Version 1.0.0 2022-04-02: Initial Release.
//
// TODO: build a booking system capable of managing a single flight with multiple stops

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "manifest.h"

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////  CONSTANTS  /////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// The buffer length is used for reading a single line
#define MAX_STRING_LEN 100

#define COMMAND_PRINT_HELP "help"
#define COMMAND_PRINT_ROUTE "print"
#define COMMAND_SUBROUTE "subroute"
#define COMMAND_CHANGE_ORIGIN "change_origin"
#define COMMAND_BYPASS "bypass"
#define COMMAND_EMERGENCY "emergency"
#define COMMAND_CANCEL "cancel"
#define COMMAND_REVERSE "reverse"
#define COMMAND_ADD_PERSON "add_person"
#define COMMAND_PRINT_MANIFEST "print_manifest"
#define COMMAND_FLIGHT_STATS "stats"

// TODO: you may choose to add additional #defines here.
#define TRUE 1 
#define FALSE 0

////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////  STRUCTS  //////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Airports represent 'stops' along the flight path
// These are the 'nodes' of the linked list
struct airport {
    char code[MAX_STRING_LEN];
    int arrival_time;
    int departure_time;
    struct airport *next_airport;
    struct manifest *manifest; 
};

// Root flight structure
// This stores the state of the current flight
// (i.e. the head and tail of the linked list)
struct flight {
    struct airport *origin_airport;
    struct airport *dest_airport;
};

////////////////////////////////////////////////////////////////////////////////
/////////////////////////////  FUNCTION PROTOTYPES  ////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Helper Functions
void remove_newline(char input[MAX_STRING_LEN]);
void do_print_help(void);

void interpret_line(
    char buffer[MAX_STRING_LEN],
    int *val0,
    int *val1,
    char word[MAX_STRING_LEN]
);

// Stage 1 Functions
struct flight *setup_flight(void);
void do_print_airports(struct flight *flight);
void print_one_airport(struct airport *ap);
struct airport *create_airport(
    char code[MAX_STRING_LEN],
    int arrival_time,
    int departure
);

// Stage 2 Functions
void do_subroute(struct flight *flight);
void do_change_origin(struct flight *flight);

// TODO: Your functions prototypes here

// Stage 1 Functions
void append(struct flight *flight, struct airport *new_airport); 
void do_bypass(struct flight *flight); 

// Stage 2 Functions 
void do_emergency(struct flight *flight); 
struct flight *do_cancel(struct flight *flight); 
void do_reverse(struct flight *flight); 

// Stage 3 Functions 
void add_manifest(struct flight *flight); 
void manifest_code(struct flight *flight); 
void manifest_final(struct flight *flight); 

////////////////////////////////////////////////////////////////////////////////
//////////////////////////  FUNCTION IMPLEMENTATIONS  //////////////////////////
////////////////////////////////////////////////////////////////////////////////

int main(void) {
    // Stage 1.1
    // TODO: Complete the setup_flight function below
    struct flight *flight = setup_flight();  

    // TODO: Fill out the while loop with relevant commands & functions
    // Move into and stay in operational mode until CTRL+D
    printf("Enter Command: ");
    char command_line[MAX_STRING_LEN];
    while (fgets(command_line, MAX_STRING_LEN, stdin) != NULL) {

        remove_newline(command_line);

        if (strcmp(COMMAND_PRINT_HELP, command_line) == 0) {
            // A help command we have implemented for you.
            do_print_help();
        } else if (strcmp(COMMAND_PRINT_ROUTE, command_line) == 0) {
            // Stage 1.2 - TODO: Complete this function below
            do_print_airports(flight);
        } else if (strcmp(COMMAND_SUBROUTE, command_line) == 0) {
            // Stage 2.1 - TODO: Complete this function below
            do_subroute(flight);
        } else if (strcmp(COMMAND_CHANGE_ORIGIN, command_line) == 0) {
            // Stage 2.2 - TODO: Complete this function below
            do_change_origin(flight);
        } else if (strcmp(COMMAND_BYPASS, command_line) == 0) { 
            // Stage 2.3 
            do_bypass(flight); 
        } else if (strcmp(COMMAND_EMERGENCY, command_line) == 0) { 
            // Stage 3.1 
            do_emergency(flight); 
        } else if (strcmp(COMMAND_CANCEL, command_line) == 0) { 
            // Stage 3.2 
            printf("Flight cancelled. Now accepting a new flight:\n"); 
            flight = do_cancel(flight);  
            free(flight); 
            flight = setup_flight(); 
        } else if (strcmp(COMMAND_REVERSE, command_line) == 0) { 
            // Stage 3.3 
            do_reverse(flight); 
        } else if (strcmp(COMMAND_ADD_PERSON, command_line) == 0) { 
            add_manifest(flight);
        } else if (strcmp(COMMAND_PRINT_MANIFEST, command_line) == 0) {
            manifest_code(flight); 
        } else if (strcmp(COMMAND_FLIGHT_STATS, command_line) == 0) { 
            manifest_final(flight); 
        }
        printf("Enter Command: ");
    }
    printf("Goodbye!\n");

    flight = do_cancel(flight);     
    free(flight); 

    return 0;
}

// Stage 1.1
// Creates and initialises a flight by asking the user for input.
// Parameters:
//     None
// Returns:
//     Pointer to the malloc'd flight
struct flight *setup_flight(void) {
    struct flight *new_flight = malloc(sizeof(struct flight));
    new_flight->origin_airport = NULL;
    new_flight->dest_airport = NULL;

    printf("How many stops will be enroute? ");
    char input_line[MAX_STRING_LEN] = {0};
    fgets(input_line, MAX_STRING_LEN, stdin);

    int num_stops = 0;
    num_stops = atoi(input_line);

    // TODO: For each airport Use fgets to read a line and then use the
    //       provided interpret_line() function to extract information.
    int i = 0; 
    int prev_depart_time = 0; 
    struct airport *prev = NULL; 
    while (i < num_stops) {
        char buffer[MAX_STRING_LEN]; 
        fgets(buffer, MAX_STRING_LEN, stdin); 
        int arrival_time = 0; 
        int departure_time = 0; 
        char airport_code[MAX_STRING_LEN]; 

        interpret_line(buffer, &arrival_time, &departure_time, airport_code);
        struct airport *new_airport = create_airport(airport_code, 
        arrival_time, departure_time);
        append(new_flight, new_airport); 
        // edge cases 
        if (new_airport->departure_time < new_airport->arrival_time) { 
            printf("Departure time cannot be before the arrival time!\n"); 
            free(new_airport); 
            prev->next_airport = NULL; 
            prev_depart_time = prev->departure_time; 
        } else if (new_airport->arrival_time < prev_depart_time) { 
            printf("New arrival time cannot be before the previous departure time\n"); 
            free(new_airport);  
            prev->next_airport = NULL; 
            prev_depart_time = prev->departure_time; 
        } else { 
            prev_depart_time = new_airport->departure_time;
            prev = new_airport; 
        }
        i++; 
    }   
    return new_flight;
}

// Stage 1.1 - Append Function 
// appends new_airport to the flight route 
// error checks the departure time and arrival time between flights
void append(struct flight *flight, struct airport *new_airport) {
    if (flight->origin_airport == NULL) { 
        flight->dest_airport = new_airport; 
        flight->origin_airport = new_airport; 
    } else { 
        flight->dest_airport->next_airport = new_airport;
        flight->dest_airport = new_airport; 
        new_airport->next_airport = NULL; 
    }
}

// Stage 1.2 
// Given a pointer to a flight struct, prints all the info about the route
// Parameters:
//     flight = the flight which contains the flight route to print
// Returns:
//     None
void do_print_airports(struct flight *flight) {

    // TODO: Loop through the flight route and call 
    //       the provided print_one_airport function
    printf("ROUTE:\n");
    struct airport *current = flight->origin_airport; 
    while (current != NULL) { 
        print_one_airport(current); 
        current = current->next_airport; 
    }
}

// Stage 1.2
// PROVIDED FUNCTION - DO NOT CHANGE
// Given a pointer to an airport struct,
// prints all the info about the airport
// Parameters:
//     ap = the airport to print
// Returns:
//     None
void print_one_airport(struct airport *ap) {
    printf(
        "%8s:    %04d -> %04d\n",
       ap->code,
       ap->arrival_time,
       ap->departure_time
    );
}

// Stage 1.1
// Given the information about a new airport,
// Uses `malloc` to create memory for it and returns a pointer to
// that memory.
// Parameters:
//     code            = the airport ICAO code
//     arrival_time    = the arrival time of the new airport
//     departure_time  = the departure time of the new airport
// Returns:
//     A pointer to the malloc'd struct airport
struct airport *create_airport(
    char code[MAX_STRING_LEN],
    int arrival_time,
    int departure_time)
{
    // Malloc new struct
    struct airport *new_airport = malloc(sizeof(struct airport));
    // initialise airport fields
 
    strcpy(new_airport->code, code);
    new_airport->arrival_time = arrival_time;
    new_airport->departure_time = departure_time;
    new_airport->next_airport = NULL;
    // new_airport->manifest = create_manifest();
    new_airport->manifest = NULL; 

    return new_airport;
}

// Stage 2.1 Calculate Subroute Function 
// Program calculates the number of hours and minutes between the origin 
// given airport's departure time, and the given airport's arrival time
void do_subroute(struct flight *flight) {
    printf("Enter airport code: "); 

    // reads in line 
    char command_line[MAX_STRING_LEN];
    fgets(command_line, MAX_STRING_LEN, stdin); 
    remove_newline(command_line);

    // head of flight route 
    struct airport *current = flight->origin_airport; 

    int end = 0; 
    int count = FALSE; 
    while (current != NULL) { 
        if (strcmp(current->code, command_line) == 0) { 
            end = current->arrival_time; 
            count = TRUE; 
        }
        current = current->next_airport; 
    }

    // converts time into hours and mins formaat 
    if (count == TRUE) { 
        int start = flight->origin_airport->departure_time; 
        int hours = (end / 100) - (start / 100); 
        int mins = (end % 100) - (start % 100); 
        int minute_diff = hours * 60 + mins;

        if (minute_diff < 0) { 
            minute_diff *= -1; 
        }

        hours = minute_diff / 60; 
        mins = minute_diff % 60; 

        printf("Time for subroute: %d hrs & %d mins\n", hours, mins);
    } else if (count == FALSE) { 
        printf("Desired subroute destination does not exist!\n"); 
    }
}

// Stage 2.2 Change Origin Function 
// Program adds an airport before the existing origin
void do_change_origin(struct flight *flight) {
    printf("Enter new origin info: "); 

    char command_line[MAX_STRING_LEN]; 
    fgets(command_line, MAX_STRING_LEN, stdin);

    int arrival_time = 0; 
    int departure_time = 0; 
    char airport_code[MAX_STRING_LEN]; 

    interpret_line(command_line, &arrival_time, &departure_time, airport_code);
    struct airport *new_airport = create_airport(airport_code, 
    arrival_time, departure_time);  

    struct airport *current = flight->origin_airport; 
    struct airport *second_head = current->next_airport;

    int count = TRUE; 
    while (current != NULL) { 
        if (strcmp(current->code, airport_code) == 0) {
            count = FALSE;  
        } 
        current = current->next_airport; 
    }
    current = flight->origin_airport; 
    if (count == FALSE) { 
        printf("New airport code is not unique!\n");
    } else if (new_airport->departure_time < new_airport->arrival_time) {
        printf("Departure time cannot be before the arrival time!\n"); 
        free(new_airport); 
    } else if (new_airport->departure_time > second_head->arrival_time) {
        printf("Departure of new origin cannot be after the arrival time of the next airport!\n"); 
        free(new_airport); 
    } else if (count == TRUE) { 
        printf("Added: %s\n", new_airport->code);
        flight->origin_airport = new_airport; 
        new_airport->next_airport = current; 
    }
}

// Stage 2.3 Bypass Airport Function 
// Program reads in the ICAO code of the airport to bypass, 
// and remove it from the flight route.
void do_bypass(struct flight *flight) { 
    printf("Enter airport code: "); 
    
    char command_line[MAX_STRING_LEN];
    fgets(command_line, MAX_STRING_LEN, stdin); 
    remove_newline(command_line);

    struct airport *current = flight->origin_airport; 

    // first edge case  
    int count = TRUE; 

    if (strcmp(current->code, command_line) == 0) {
        struct airport *first = flight->origin_airport; 
        flight->origin_airport = flight->origin_airport->next_airport; 
        current = current->next_airport; 
        free(first); 
        count = FALSE; 
    } 

    struct airport *previous = NULL; 
    while (current != NULL) {
        if (strcmp(current->code, command_line) == 0) {
            struct airport *remove = current; 
            previous->next_airport = previous->next_airport->next_airport;
            current = current->next_airport; 
            free(remove);
            count = FALSE; 
        } else { 
            previous = current; 
            current = current->next_airport; 
        }
    }
    if (count == TRUE) { 
        printf("No airport of that code exists!\n");
    } 
}

// Stage 3.1 Emergency Function 
// Program read in the number of hours until an emergency landing. 
// The time of the emergency landing will be the departure time of the origin airport, 
// plus the number of hours that was just read in.
void do_emergency(struct flight *flight) { 
    printf("How long until emergency: "); 
    char input_line[MAX_STRING_LEN] = {0};
    fgets(input_line, MAX_STRING_LEN, stdin);
    int hours = 0;
    hours = atoi(input_line);
    hours *= 100;
    int emergency_time = flight->origin_airport->departure_time + hours; 

    char alt[MAX_STRING_LEN] = "ALT0"; 
    int departure_time = 0; 
    struct airport *emergency_airport = create_airport(alt, 
    emergency_time, departure_time); 
    
    struct airport *current = flight->origin_airport; 
    struct airport *previous = NULL; 
    while (current != NULL && current->next_airport != NULL && hours != 0) {
        if (emergency_airport->arrival_time < current->arrival_time) {
            previous->next_airport = emergency_airport;
            emergency_airport->next_airport = current; 
            current = current->next_airport;
        } else { 
            previous = current; 
            current = current->next_airport; 
        }
    }
    current = flight->origin_airport; 
    if (hours == 0) {
        current->departure_time = 0;  
        while (current->next_airport != NULL) { 
            struct airport *new = current->next_airport->next_airport; 
            free(current->next_airport); 
            current->next_airport = new; 
        }
    } else if (emergency_airport->arrival_time > flight->dest_airport->arrival_time) { 
        printf("Flight was safe!\n"); 
    } else {
        while (emergency_airport->next_airport != NULL) { 
            struct airport *new = emergency_airport->next_airport->next_airport; 
            free(emergency_airport->next_airport); 
            emergency_airport->next_airport = new; 
        }
    }
}

// Stage 3.2 Cancel Flight Function 
// Program should delete all airports from the route. 
struct flight *do_cancel(struct flight *flight) {
    struct airport *current = flight->origin_airport; 
    struct airport *temp = flight->origin_airport; 
    while (temp != NULL) { 
        current = current->next_airport;
        delete_manifest(temp->manifest);   
        free(temp); 
        temp = current;  
    } 
    return flight; 
}

// Stage 3.3 Reverse Flight Function 
// Program reverses the flight route. 
void do_reverse(struct flight *flight) { 
    struct airport *previous = NULL; 
    struct airport *next = NULL; 
    struct airport *head = flight->origin_airport; 
    while (head != NULL) {
        next = head->next_airport; 
        head->next_airport = previous; 
        // linking the previous to the head
        previous = head; 
        // linking to the previous to the head
        head = next; 
    }
    flight->origin_airport = previous; 
}

// Stage 4.1 Add People to Airport Function
// Program add the person into the manifest of the airport that matches the given code.
void add_manifest(struct flight *flight) {
    printf("Enter the airport code: "); 
    char code[MAX_STRING_LEN]; 
    fgets(code, MAX_STRING_LEN, stdin);
    remove_newline(code);
    
    printf("Enter the passenger name: ");
    char name[MAX_STRING_LEN]; 
    fgets(name, MAX_STRING_LEN, stdin);
    remove_newline(name);
    
    printf("Enter the passenger weight: "); 
    char weight_line[MAX_STRING_LEN] = {0};
    fgets(weight_line, MAX_STRING_LEN, stdin);
    remove_newline(weight_line); 
    double weight = 0;
    weight = atof(weight_line);

    int count = FALSE;  
    struct airport *current = flight->origin_airport;
    while (current != NULL) {
        
        if (strcmp(code, current->code) == 0) { 
            // add_person(current->manifest, name, weight); 
            // count = TRUE; 
            if (current->manifest == NULL) { 
                current->manifest = create_manifest(); 
                add_person(current->manifest, name, weight); 
                count = TRUE; 
            } else {
                add_person(current->manifest, name, weight); 
                count = TRUE; 
            }
        } 
        current = current->next_airport; 
    }
    
    if (count == FALSE) { 
        printf("No airport of that code exists!\n"); 
    }
}

// Stage 4.2 Print Manifest Function
// Program should read in the name of the airport to 
// print the manifest of and then display the manifest 
// of people and their weight in the following format.
void manifest_code(struct flight *flight) { 
    printf("Enter the airport code: "); 
    char code[MAX_STRING_LEN]; 
    fgets(code, MAX_STRING_LEN, stdin);
    remove_newline(code);

    int count = FALSE; 
    struct airport *current = flight->origin_airport; 
    while (current != NULL) { 
        if (strcmp(current->code, code) == 0 && current->manifest != NULL) { 
            print_manifest(current->manifest);
            count = TRUE; 
        } 
        current = current->next_airport;
    }
    if (count == FALSE) { 
        printf("No airport of that code exists!\n"); 
    }
}

// Stage 4.3 Statistics Final Manifest 
// Program merge all the manifests together at the destination airport. 
// Next, it should display the list of all people now at the destination 
// airport and the total weight of everyone.
void manifest_final(struct flight *flight) { 
    printf("Final manifest:\n"); 

    // reverses the flight so dest is now origin
    do_reverse(flight); 

    struct airport *head = flight->origin_airport;
    struct airport *current = flight->origin_airport;
    
    while (current != NULL) { 
        struct manifest *current_manifest = current->manifest; 
        if (current_manifest == NULL) { 
            head->manifest = join_manifest(head->manifest, current_manifest); 
        } 
        current = current->next_airport; 
    }

    print_manifest(head->manifest); 

    double total_weight = manifest_weight(head->manifest); 
    printf("Total Weight: %lf\n", total_weight); 

    do_reverse(flight); 
}

////////////////////////////////////////////////////////////////////////////////
//////////////////////////////  HELPER FUNCTIONS  //////////////////////////////
////////////////////////////////////////////////////////////////////////////////

// Helper Function
// You likely do not need to change this function.
//
// Given a raw string will remove and first newline it sees.
// The newline character wil be replaced with a null terminator ('\0')
// Parameters:
//     flight  = the flight to move people along of
// Returns:
//     None
void remove_newline(char input[MAX_STRING_LEN]) {

    // Find the newline or end of string
    int index = 0;
    while (input[index] != '\n' && input[index] != '\0') {
        index++;
    }
    // Goto the last position in the array and replace with '\0'
    // Note: will have no effect if already at null terminator
    input[index] = '\0';
}


// Helper Function
// You DO NOT NEED TO UNDERSTAND THIS FUNCTION, and will not need to change it.
//
// Given a raw string in the following foramt: [integer0] [integer1] [string]
// This function will extract the relevant values into the given pointer variables.
// The function will also remove any newline characters.
//
// For example, if given: "0135 0545 YSSY"
// The function will put the integer values
//     135 into the val1 pointer
//     545 into the val2 pointer
// And will copy a null terminated string
//     "YSSY" into the 'word' array
//
// If you are interested, `strtok` is a function which takes a string,
// and splits it up into before and after a "token" (the second argument)
//
// Parameters:
//     buffer  = A null terminated string in the following format
//               [integer0] [integer1] [string]
//     val0    = A pointer to where [integer0] should be stored
//     val1    = A pointer to where [integer1] should be stored
//     word    = An array for the [string] to be copied into
// Returns:
//     None
void interpret_line(
    char buffer[MAX_STRING_LEN],
    int *val0,
    int *val1,
    char word[MAX_STRING_LEN]) 
{

    // Remove extra newline
    remove_newline(buffer);

    // Extract value 1 as int
    char *val0_str = strtok(buffer, " ");
    if (val0_str != NULL) {
        *val0 = atoi(val0_str);
    } else {
        *val0 = -1;
    }

    // Extract value 2 as int
    char *val1_str = strtok(NULL, " ");
    if (val1_str != NULL) {
        *val1 = atoi(val1_str);
    } else {
        *val1 = -1;
    }

    char *word_str = strtok(NULL, " ");
    if (word_str != NULL) {
        // Extract word
        strcpy(word, word_str);
    }

    if (val0_str == NULL || val1_str == NULL || word_str == NULL) {
        // If any of these are null, there were not enough words.
        printf("Could not properly interpret line: %s.\n", buffer);
    }

}

void do_print_help(void) {
    printf("+-----------------+-------------------------------------------+\n");
    printf("|Command Name     | How to Use                                |\n");
    printf("+=================+===========================================+\n");
    printf("|PRINT ROUTE      | Enter command: print                      |\n");
    printf("+-----------------+-------------------------------------------+\n");
    printf("|SUBROUTE         | Enter command: subroute                   |\n");
    printf("|                 | Enter airport code: [AIRPORT CODE]        |\n");
    printf("+-----------------+-------------------------------------------+\n");
    printf("|CHANGE ORIGIN    | Enter command: change_origin              |\n");
    printf("|                 | Enter new origin info: [ARRIVAL TIME]...  |\n");
    printf("|                 |     ... [DEPARTURE TIME] [AIRPORT CODE]   |\n");
    printf("+-----------------+-------------------------------------------+\n");
    printf("|BYPASS           | Enter command: bypass                     |\n");
    printf("|                 | Enter airport code: [AIRPORT CODE]        |\n");
    printf("+-----------------+-------------------------------------------+\n");
    printf("|EMERGENCY        | Enter command: emergency                  |\n");
    printf("|                 | How long until emergency: [TIME IN HOURS] |\n");
    printf("+-----------------+-------------------------------------------+\n");
    printf("|CANCEL           | Enter command: cancel                     |\n");
    printf("+-----------------+-------------------------------------------+\n");
    printf("|REVERSE          | Enter command: reverse                    |\n");
    printf("+-----------------+-------------------------------------------+\n");
    printf("|                 | Enter command: add_person                 |\n");
    printf("|ADD PERSON       | Enter the airport code: [AIRPORT CODE]    |\n");
    printf("|                 | Enter the passenger name: [NAME]          |\n");
    printf("|                 | Enter the passenger weight: [WEIGHT]      |\n");
    printf("+-----------------+-------------------------------------------+\n");
    printf("|PRINT MANIFEST   | Enter command: print_manifest             |\n");
    printf("|                 | Enter the airport code: [AIRPORT CODE]    |\n");
    printf("+-----------------+-------------------------------------------+\n");
    printf("|FLIGHT STATISTICS| Enter command: stats                      |\n");
    printf("+-----------------+-------------------------------------------+\n");
}

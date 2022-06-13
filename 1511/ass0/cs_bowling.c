// cs_bowling
// cs_bowling.c
// 
// This program was written by Ze Sheng (z5421872)
// on 28/02/2022
//  
// A program that calculates the scores for a 10 pin bowling game.
#include <stdio.h> 

#define TRUE 1 
#define FALSE 0

int main(void) { 
    int bowl_1;
    int bowl_2;
    int bonus_bowl; 
    int score = 0;
    int total_score = 0; 

    printf("Welcome to CS Bowling!\n");
    // Counters
    int frames = 1;
    int spare_bonus = 0;
    int strike_bonus = 0; 
    // Loop
    while (frames <= 10) { 
        // Bowl 1 
        printf("Frame %d, Bowl 1: ", frames);  
        scanf("%d", &bowl_1); 
        if ((bowl_1 < 0) || (bowl_1 > 10)) {
            bowl_1 = 0; 
            printf("Bowl 1 invalid!\n"); 
        } else if (bowl_1 == 10) { 
            printf("Score for Frame: 10\n"); 
            printf("Strike! Bonus for this frame is next two rolls.\n");
            score += bowl_1; 
        } else { 
            score += bowl_1; 
        }
        // Bowl 2 
        if (bowl_1 != 10) { 
            printf("Frame %d, Bowl 2: ", frames);
            scanf("%d", &bowl_2);
            if ((bowl_2 < 0) || (bowl_2 > 10 - bowl_1 )) {
                printf("Bowl 2 invalid!\n");
                bowl_2 = 0; 
            } else if (bowl_2 == 10 - bowl_1) { 
                printf("Score for Frame: 10\n"); 
                printf("Spare! Bonus for this frame is next roll.\n"); 
                score += bowl_2;        
            } else { 
                score += bowl_2; 
            }
        } 
        // Score for Frame
        if (score != 10) { 
            printf("Score for Frame: %d\n", score); 
        }
        // Bonus Bowl 
        if ((frames == 10) && (score == 10)) {  
            printf("Bonus Bowl 1: "); 
            scanf("%d", &bonus_bowl); 
            if ((bonus_bowl < 0) || (bonus_bowl > 10)) {
                printf("Bonus Bowl Invalid!\n"); 
            } else { 
                total_score += bonus_bowl * 2;
            }
        } 
        // Spare Bonus
        if (spare_bonus == TRUE) { 
            total_score += bowl_1; 
            spare_bonus = FALSE;
        } else { 
            spare_bonus = FALSE; 
        }
        // Strike Bonus
        if (strike_bonus == 1) { 
            total_score += score; 
            strike_bonus = FALSE; 
        } else { 
            strike_bonus = FALSE; 
        }
        // Flag Counter
        if (bowl_2 == 10 - bowl_1) {
            spare_bonus = TRUE; 
        } else if (bowl_1 == 10) { 
            strike_bonus = TRUE; 
        } 
        total_score += score;
        score = 0; 
        frames += 1;
    }
    // Total Score 
    printf("Total Score: %d\n", total_score);
    return 0;
}  

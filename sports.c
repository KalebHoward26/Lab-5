#include <stdio.h>

int main() {
    int score;
    
    // this continues to prompt for a score until it is 0 or 1, stopping our while loop.
    while (1) {
        printf("Enter the NFL score (enter 0 or 1 to stop): "); 
        scanf("%d", &score); // saves the score to our score variable.
        
        if (score <= 1) { // breaks the program if we get something less than or 1.
            printf("program has been terminated.\n");
            break;
        }
        
        printf("possible combinations of scoring plays:\n"); // prints the header for the list of combos.
        
        // nested for loops in order to generate all the combinations.
      for (int td = 0; td * 6 <= score; td++) {
            for (int fg = 0; fg * 3 <= score - td * 6; fg++) {
                for (int safety = 0; safety * 2 <= score - td * 6 - fg * 3; safety++) {
                    int remaining_score = score - td * 6 - fg * 3 - safety * 2;
                    
                    if (remaining_score == 0) {
                        printf("0 TD + 2pt, %d TD + FG, 0 TD, 0 3pt FG, %d Safety\n", td, safety);
                    }
                    else if (remaining_score == 1 && td > 0) {
                        printf("0 TD + 2pt, %d TD + FG, 0 TD, 0 3pt FG, %d Safety\n", td, safety);
                    }
                    else if (remaining_score == 2 && td > 0) {
                        printf("0 TD + 2pt, %d TD + FG, 1 TD, 0 3pt FG, %d Safety\n", td, safety);
                    }
                    else if (remaining_score == 3) {
                        printf("0 TD + 2pt, %d TD + FG, 1 TD, 0 3pt FG, %d Safety\n", td, safety);
                    }
                    else if (remaining_score == 4 && td > 0) {
                        printf("0 TD + 2pt, %d TD + FG, 1 TD, 0 3pt FG, %d Safety\n", td, safety);
                    }
                    else if (remaining_score == 5) {
                        printf("0 TD + 2pt, %d TD + FG, 1 TD, 1 3pt FG, %d Safety\n", td, safety);
                    }
                    else if (remaining_score == 6 && td > 0) {
                        printf("0 TD + 2pt, %d TD + FG, 1 TD, 1 3pt FG, %d Safety\n", td, safety);
                    }
                    else if (remaining_score == 7) {
                        printf("0 TD + 2pt, %d TD + FG, 1 TD, 1 3pt FG, %d Safety\n", td, safety);
                    }
                    else if (remaining_score == 8 && td > 0) {
                        printf("0 TD + 2pt, %d TD + FG, 1 TD, 1 3pt FG, %d Safety\n", td, safety);
                    }
                    else if (remaining_score == 9) {
                        printf("0 TD + 2pt, %d TD + FG, 1 TD, 2 3pt FG, %d Safety\n", td, safety);
                    }
                    else if (remaining_score == 10 && td > 0) {
                        printf("0 TD + 2pt, %d TD + FG, 1 TD, 2 3pt FG, %d Safety\n", td, safety);
                    }
                    else if (remaining_score == 11) {
                        printf("0 TD + 2pt, %d TD + FG, 1 TD, 2 3pt FG, %d Safety\n", td, safety);
                    }
                }
            }
        }
    }

    return 0;
}
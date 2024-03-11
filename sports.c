#include <stdio.h>

int main() {
    int score;
    
    // this continues to prompt for a score until it is 0 or 1, stopping our while loop.
    while (1) {
        printf("Enter the NFL score ( 0 or 1 to stop): "); 
        scanf("%d", &score); // saves the score to our score variable.
        
        if (score <= 1) { // breaks the program if we get something less than or 1.
            printf("program has been terminated.\n");
            break;
        }
        
        printf("possible combinations of scoring plays:\n"); // prints the header for the list of combos.
        
        // nested for loops in order to generate all the combinations.
      for (int td = 0; td * 6 <= score; td++) {
            for (int fg = 0; fg * 3 <= score - td * 6; fg++) { // beginning i tried to just simply do every single one with a for loop, and for some reason it was finding way less than all the possibilites. 
                for (int safety = 0; safety * 2 <= score - td * 6 - fg * 3; safety++) { // eventually i googled to try to find out why, and eventually i was here, inputting all these mathematical possibilities for each remaining possibility of score.
                    int remaining_score = score - td * 6 - fg * 3 - safety * 2; // this is probably way harder than the best way, but I think I got it to eventually work well.
                    // this stuff below i got help from a few different stack overflow threads that talked about similar types of problems. 
                    if (remaining_score == 0) { // i used the sample of 25 to ensure i was not missing anything obvious and corrected from there.
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
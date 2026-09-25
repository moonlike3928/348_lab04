#include <stdio.h>

// need to solve 6t + 3f + 2s + 8(a) + 7(b) = points for all values of t, f, s, a, b


// validate input is >= 0
int validateInput(int input) {
   if (input >= 1) {
       return 1;
   }
   return 0;
}

// this sucks dude

// Find all valid combinations of multiples, check againts point value.
void findCombinations(int score) {
    for (int t = 0; t * 6 <= score; t++) { // touchdowns
        for (int f = 0; f * 3 <= score; f++) { // field goals
            for (int s = 0; s * 2 <= score; s++) { // safetys
                for (int a = 0; a * 8 <= score; a++) { // TD + 2 point conversion
                    for (int b = 0; b * 7 <= score; b++) { // TD + field goal
                        if (6*t + 3*f + 2*s + 8*a + 7*b == score) { // check if valid solution
                            printf("%d TD, %d FG, %d Safety, %d TD+2pt, %d TD+FG\n",
                                   t, f, s, a, b);
                        }
                    }
                }
            }
        }
    }
}


int main(void) {
    int input = -1;
    printf("Please enter a score (1 to exit): ");
    scanf("%d", &input);

    while ( !validateInput(input) ) {
        printf("Invalid input. Please try again.\n");
        scanf("%d", &input);
    }

    if (input == 1) {
        printf("Exiting...");
        return 0;
    }

    findCombinations(input);

    return 0;
}

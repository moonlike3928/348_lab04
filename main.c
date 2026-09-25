#include <stdio.h>

// need to solve 6t + 3f + 2s + 8(tdc) + 7(tdf) = points for all values of t, f, s, tdc, tdf


// validate input is >= 0
int validateInput(int input) {
   if (input >= 0) {
       return 1;
   }
   return 0;
}

int main(void) {
    int input = -1;
    printf("Please enter a score: ");
    scanf("%d", &input);

    while ( !validateInput(input) ) {
        printf("Invalid input. Please try again.\n");
        scanf("%d", &input);
    }
    if (input == 0) {
        return 0;
    }
    return 0;
}

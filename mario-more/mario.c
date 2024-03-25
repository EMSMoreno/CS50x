#include <cs50.h>
#include <stdio.h>

int main(void) {
    int height;

    do {
        printf("Height: ");
        if (scanf("%d", &height) != 1 || height < 1 || height > 8) {
            // If input is not an integer between 1 and 8, clear the input buffer and reprompt
            while (getchar() != '\n') {}
        } else {
            // Input is valid, break out of loop
            break;
        }
    } while (1);

    // Pyramid
    for (int i = 1; i <= height; i++) {
        // Spaces
        for (int j = height - i; j > 0; j--) {
            printf(" ");
        }

        // Left Pyramid
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        // Gap between pyramids
        printf("  ");

        // Right pyramid
        for (int j = 0; j < i; j++) {
            printf("#");
        }

        // Move to next row
        printf("\n");
    }

    return 0;
}

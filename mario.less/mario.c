#include <stdio.h>

int main() {
    int height;

    do {
        printf("Enter the height of the pyramid (a positive integer): ");
        scanf("%d", &height);
        while (getchar() != '\n');
    } while (height <= 0);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height - i - 1; j++) {
            printf(" ");
        }
        for (int k = 0; k < i + 1; k++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}

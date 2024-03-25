#include <stdio.h>

int main(void) {
    int start_size, end_size, years = 0;
    do {
        printf("Enter starting population size (must be >= 9): ");
        scanf("%d", &start_size);
    } while (start_size < 9);
    do {
        printf("Enter ending population size (must be >= starting size): ");
        scanf("%d", &end_size);
    } while (end_size < start_size);
    int population = start_size;
    while (population < end_size) {
        population += population / 3 - population / 4;
        years++;
    }
    printf("Years: %d\n", years);
    return 0;
}

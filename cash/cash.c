#include <stdio.h>
#include <cs50.h>

int main(void) {
    int change_owed;

    do {
        change_owed = get_int("Change owed (in cents): ");
    } while (change_owed < 0);

    int coins_count = 0;
    int denominations[] = {25, 10, 5, 1};

    for (int i = 0; i < sizeof(denominations) / sizeof(denominations[0]); i++) {
        coins_count += change_owed / denominations[i];
        change_owed %= denominations[i];
    }

    printf("%d\n", coins_count);
    return 0;
}

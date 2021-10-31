#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>
#include <locale.h>

#include "wishes.h"
#include "characters.h"
#include "array_utils.h"

void filterNonFocus4stars() {
    int i;
    int n = 0;
    for (i = 0; i < sizeof(all4stars) / sizeof(all4stars[0]); i++) {
        if (getIndexOfElementInArray(focus4stars, all4stars[i]) == -1) {
            nonFocus4stars[n] = all4stars[i];
            n++;
        }
    }
    return;
}

double randomDouble(double min, double max) {
    return rand() / 32767.0 * (max - min) + min;
}

int randomInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    filterNonFocus4stars(); // remove focus4stars from all4stars and create nonFocus4stars with the remaining elements
    
    #ifdef _WIN32
    srand(GetTickCount());
    #else
    srand(time(NULL));
    #endif

    // allow french accents
    // setlocale(LC_ALL, ""); // not working

    // defining variables
    int count = 0;
    int pity5 = 0;
    int pity4 = 0;

    bool estGaranti5 = false;
    bool estGaranti4 = false;

    int count5stars = 0;
    int count4stars = 0;

    bool continuePull = true;

    char c;
    double luck;

    // main loop
    while (continuePull) {
        int i;
        for (i = 0; i < 10; i++)
        {
            count++;
            pity5++;
            pity4++;
            luck = randomDouble(0, 10000) / 100;
            if (luck <= getProba5stars(pity5)) {
                if (!estGaranti5) {
                    if (randomInt(1,2) == 1) {
                        printf("\033[93m%i. %s (5 stars - Focus 50/50) - Pity : %i\033[0m\n", count, focus5stars, pity5);
                    }
                    else {
                        printf("\033[93m%i. %s (5 stars - Non Focus 50/50) - Pity : %i\033[0m\n", count, nonFocus5stars[randomInt(0, sizeof(nonFocus5stars) / sizeof(nonFocus5stars[0]) - 1)], pity5);
                        estGaranti5 = true;
                    }
                }
                else {
                    printf("\033[93m%i. %s (5 stars - Garanti) - Pity : %i\033[0m\n", count, focus5stars, pity5);
                    estGaranti5 = false;
                }
                pity5 = 0;
                count5stars++;
            } else if (luck <= getProba4stars(pity4)) {
                if (!estGaranti4) {
                    if (randomInt(1,2) == 1) {
                        printf("\033[95m%i. %s (4 stars - Focus 50/50) - Pity : %i\033[0m\n", count, focus4stars[randomInt(0, sizeof(focus4stars) / sizeof(focus4stars[0]) - 1)], pity5);
                    }
                    else {
                        printf("\033[95m%i. %s (4 stars - Non Focus 50/50) - Pity : %i\033[0m\n", count, nonFocus4stars[randomInt(0, sizeof(nonFocus4stars) / sizeof(nonFocus4stars[0]) - 1)], pity5);
                        estGaranti4 = true;
                    }
                }
                else {
                    printf("\033[95m%i. %s (4 stars - Garanti) - Pity : %i\033[0m\n", count, focus4stars[randomInt(0, sizeof(focus4stars) / sizeof(focus4stars[0]) - 1)], pity5);
                    estGaranti4 = false;
                }
                pity4 = 0;
                count4stars++;
            } else {
                printf("%i. %s (3 stars) - Pity : %i\n", count, weapon4stars[randomInt(0, sizeof(weapon4stars) / sizeof(weapon4stars[0]) - 1)], pity5);
            }
        }
        scanf("%c", &c);
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#include "wishes.h"
#include "characters.h"
#include "array_utils.h"

void filterNonFocus4stars() {
    int i;
    int n = 0;
    for (i = 0; i < sizeof(nonFocus4starsTmp) / sizeof(nonFocus4starsTmp[0]); i++) {
        if (getIndexOfElementInArray(focus4stars, nonFocus4starsTmp[i]) == -1) {
            nonFocus4stars[n] = nonFocus4starsTmp[i];
            n++;
            // printf("%d. %s\n", n, nonFocus4starsTmp[i]);
        }
    }
    return;
}

int main() {
    copyArray(all4stars, nonFocus4starsTmp);
    filterNonFocus4stars(); // remove focus4stars from all4stars and create nonFocus4stars with the remaining elements
    
    int count = 0;
    int pity5 = 0;
    int pity4 = 0;

    bool estGaranti5 = false;
    bool estGaranti4 = false;

    int count5stars = 0;
    int count4stars = 0;

    bool continuePull = true;

    while (continuePull) {
        int i;
        for (i = 0; i < 10; i++)
        {
            printf("%d", i);
        }
        break;
    }
    return 0;
}
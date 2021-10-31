#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
int randomNumber(int min, int max) {
    srand(time(NULL));
    return rand() % (max + 1) + min;
}

int main() {
    printf("%d", randomNumber(0,100));
    return 0;
}
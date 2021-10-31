#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<time.h>
int randomNumber(int max) {
    srand(time(NULL));
    return rand() % (max + 1);
}

int main() {
    printf("%d", randomNumber(100));
    return 0;
}
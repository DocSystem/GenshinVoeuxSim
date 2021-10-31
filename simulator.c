#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
    while(1){
        const int max = 2, min = 0;
        printf("%d\n", (rand() % (max - min + 1)) + min);
    }
}
#include<cs50.h>
#include<stdio.h>

int main(void){
    printf("minutes: ");
    int min = GetInt();
    printf("bottles: %i\n", min*12);
}
#include <cs50.h>
#include <stdio.h>

int main(void){
    int coins=0;
    float money = 0.00;
    do{
         printf("Enter the money:");
         money = GetFloat();
    }while(money<0);
    money*=100;
    while(money>=25){
        money = money - 25;
        coins = coins + 1;
    }
    while(money>=10){
        money = money - 10;
        coins = coins + 1;
    }
    while(money>=05){
        money = money - 05;
        coins = coins + 1;
    }
    while(money>=01){
        money = money - 01;
        coins = coins + 1;
    }
    printf("%d\n",coins);
    return 0;
}

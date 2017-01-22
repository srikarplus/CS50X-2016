#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void){
    string name = GetString();
    int i,j;
    for(i=0,j = strlen(name);i<j;i++){
        if(i==0){
            if((int)name[i]>=65 && (int)name[i]<=90){
                printf("%c",name[i]);
            }else{
                printf("%c",name[i]-32);
            }
        }
        if(name[i]==(char)32){
            if((int)name[i+1]>=65 && (int)name[i+1]<=90){
                printf("%c",name[i+1]);
            }else{
                printf("%c",name[i+1]-32);
            }
        }
    }printf("\n");
    return 0;
}
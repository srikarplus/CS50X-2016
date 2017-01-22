#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int args, string argv[]){
    if(args != 2){
        printf("Error");
        return 1;
    }
    string msg = GetString();
    int key = atoi(argv[1]);
    int j = strlen(msg);
    int i = 0;
    for(i = 0;i < j;i++){
        
        if((int)msg[i]>=65 && (int)msg[i]<=90) {
           int k = ((int)msg[i] + key -64) % 26;
           printf("%c",(char)(k +64));
            
        }else if((int)msg[i]>=97 && (int)msg[i]<=122){
            int k = ((int)msg[i] + key -96) % 26;
            printf("%c",(char)(k +96));
        }else{
            printf("%c",msg[i]);
        }
    }
    printf("\n");   
    return 0;
}
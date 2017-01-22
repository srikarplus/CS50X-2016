#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int args, string argv[]){
    
    if(args != 2){
        printf("Error");
        return 1;
    }
    
    string key = argv[1];int q = 0;int p = strlen(key);
    for(q=0;q<p;q++){
        if(key[q]=='0' || key[q]=='1' || key[q]=='2' || key[q]=='3' || key[q]=='4' ||
             key[q]=='5' || key[q]=='6' || key[q]=='7' || key[q]=='8' || key[q]=='9'){
                 printf("Error");
                 return 1;
             }
    }
    
    
    string msg = GetString();
    int j = strlen(msg);
    int i = 0; q = 0;
    for(i = 0;i < j;i++){
        
        if((int)msg[i]>=65 && (int)msg[i]<=90) {
           int k = ((int)msg[i] + (int)key[q] -64 -65) % 26;
           printf("%c",(char)(k +64));
           q++;
            
        }else if((int)msg[i]>=97 && (int)msg[i]<=122){
            int k = ((int)msg[i] + (int)key[q] -96 -97) % 26;
            printf("%c",(char)(k +96));
            q++;
        }else{
            printf("%c",msg[i]);
        }
        
        if(q==p){
            q = 0;
        }
    }
    printf("\n");   
    return 0;
}


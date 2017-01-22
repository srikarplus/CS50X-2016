#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t  BYTE;

int main(int argc, char* argv[]){
    
   
    char* infile = "card.raw";
    char name[10];
    
    BYTE mem[512];
    int d = 1;
    
    int counter = -1;
    
    FILE* img = fopen(infile,"r");
    
    if(img == NULL){
        printf("Could not open file %s",infile);
        return 1;
    }
    
    while(true){
        counter++;
        do{
             fread(mem,512,1,img);
        }while(!((mem[0] == 0xff) && (mem[1] == 0xd8) && (mem[2] == 0xff) && (mem[3] >= 0xe0) && (mem[3] <= 0xef)));
       
        sprintf(name,"%03d.jpg",counter);
        FILE* photo = fopen(name,"w");
        
       do{
            fwrite(mem,512,1,photo);
            d= fread(mem,512,1,img);
            if(d != 1)  break;
        }while(!((mem[0] == 0xff) && (mem[1] == 0xd8) && (mem[2] == 0xff) && (mem[3] >= 0xe0) && (mem[3] <= 0xef)));
        
        
        fseek(img,-512,SEEK_CUR);
        fclose(photo);
        if(d != 1)  break;
    }
    
    
    fclose(img);
    return 0;
    
}
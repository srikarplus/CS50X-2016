#include<cs50.h>
#include<stdio.h>

int main(void){
    int height;
    do{
        // printf("Enter the height of the half pyramid :");
        // scanf("%d",&height);
        printf("Height:");
        height = GetInt();
    }while(height < 0 || height > 23); 
    int x,y,z,dummy,dummy1;
    dummy=0;    
    for(x=0;x<height;x++){
        dummy1=dummy;
        for(y=dummy;y<height-1;y++){
            printf(" ");
        }
        for(z=height+1;z>height;z--){
            printf("##");
            while(dummy1){
                printf("#");
                dummy1--;
            }
        }
        printf("\n");        
        dummy++;
    }
    return 0;
}
#inlcude<stdio.h>
int main(void){
  int x = 1;
  int y = 2;
  printf("X = %d, Y = %d", x,y);
  
  //swapping...
  int temp = x;
  x = y;
  y = temp;
  
  printf("X = %d, Y = %d", x,y);
  return 0;
}
  

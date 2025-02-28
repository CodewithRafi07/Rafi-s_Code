// calculates the area of a rectangle

#include<stdio.h>

int main(){

   int length, width, Area;
   printf("Enter length\n");
   scanf("%d", &length);

     printf("Enter breadth\n");
     scanf("%d", &width);

     Area = (length*width);

    printf("The area of this rectangle is %d", Area );
    return 0;
} 
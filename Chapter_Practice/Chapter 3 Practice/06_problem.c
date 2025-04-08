#include <stdio.h>

int main(){
    int ASCII;
    printf("Enter the number: \n");
    scanf("%d" , &ASCII);
    if (ASCII >= 97 && ASCII <= 122){
         printf("The number is %d\n" , ASCII);
         printf("The value of number is %c\n" , ASCII);
         printf("This is a lowercase\n");
    }
    else{
         printf("The number is %d\n" , ASCII);
         printf("The value of number is %c\n" , ASCII);
         printf("This is not a lowercase");
    }

    return 0;
}

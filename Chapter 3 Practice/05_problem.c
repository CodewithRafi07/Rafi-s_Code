#include <stdio.h>

int main(){
    char ASCII;
    printf("Enter the charecter: \n");
    scanf("%char" , &ASCII);
    if (ASCII >= 97 && ASCII <= 122){
         printf("The charecter is %c\n" , ASCII);
         printf("The value of character is %d\n" , ASCII);
         printf("This is a lowercase\n");
    }
    else{
         printf("The charecter is %c\n" , ASCII);
         printf("The value of character is %d\n" , ASCII);
         printf("This is not a lowercase");
    }

    return 0;
}
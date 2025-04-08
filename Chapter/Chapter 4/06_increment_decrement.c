#include <stdio.h>

int main(){
    int i = 5;
    printf("The value of i is %d\n" , i);

    i = i + 5; 
    printf("The value of i is %d\n" , i);

    printf("The value of i is %d\n" , i++);
    printf("The value of i is %d\n" , i);

    // i++ prints i first and then increments i (Post increment Operator)
    // ++i increments i first and then prints i (Post increment Operator)

    i +=2; //same as i = i + 2
    printf("The value of i is %d\n" , i);

    return 0;
}
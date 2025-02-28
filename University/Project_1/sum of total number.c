// sum of total number

#include <stdio.h>

int main(){
    int n, a1, aL, sum;
    //printf("Total Number n:");
    //scanf("%d" , &n);

    printf("First NUmber a1:");
    scanf("%d" , &a1);

    printf("Last NUmber aL:");
    scanf("%d" , &aL);

    n = (aL - a1) + 1;
    
    sum = (n * (a1 + aL))/2;
    printf("The sum of the total number is %d\n" , sum);
    
    return 0;
}
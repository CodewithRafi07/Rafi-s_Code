// sum of the muultiplication table
#include <stdio.h>

int main(){
    int n,  sum = 0;
    printf("Enter the number that you want to sum its multiplication table:");
    scanf("%d" , &n);
    for (int i = 0; i <= 10; i++)
    {
        sum = sum + (n * i);
    }

    printf("The sum of the table is %d" , sum);
    
    return 0;
}
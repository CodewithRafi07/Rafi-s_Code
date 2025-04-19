#include <stdio.h>

int main(){
    int i = 1 , sum = 0;
    while (i<=10)
    
    {
        sum = sum + i;
        i++;
    }
    printf("The sum of the first TEN natural number is %d", sum);
    
    return 0;
}
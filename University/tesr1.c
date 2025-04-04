#include <stdio.h>

int main(){
    
    int sum= 0;

    for (int i = 20; i <= 30; i++)
   

    {
        printf("%d\n" , i);
        sum = sum + i;
    }
    
    printf("The sum is %d\n" , sum);

    
    return 0;
}
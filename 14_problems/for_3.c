// factorial

#include <stdio.h>

int main(){
    int product=1;
    int n;
    printf("Enter the n:");
    scanf("%d" , &n);

    for (int i = 1; i <= n; i++)
    {
        product = product * i;
    }

    printf("The factorial is %d" , product);
    

    return 0;
}
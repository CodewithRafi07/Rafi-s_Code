#include <stdio.h>

int main(){
    int a = 15;
    int b = 3;
    int c = a + b;
    printf("The value of a is %d and the value of b is %d and sum is %d\n", a, b, c);
    // Modulus operator is used to get the remainder
    printf("The remainder when a is divided by b is: %d\n", a%b);
    return 0;
}
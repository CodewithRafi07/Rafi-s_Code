#include <stdio.h>

int main() {
    int sum = 0;

    for (int i = 21; i <= 30; i += 2) 
    
    { // Start from 21 and increment by 2
        printf("%d\n", i);
        sum += i;
    }

    printf("Sum of odd numbers: %d\n", sum);

    return 0;
}

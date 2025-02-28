// Even or Odd 

#include <stdio.h>

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    (num % 2 == 0) ? printf("%d is Even Number.\n", num) : printf("%d is Odd Number.\n", num);

    return 0;
}

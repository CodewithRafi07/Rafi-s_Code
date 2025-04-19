//print value given upto 10
#include <stdio.h>

int main() {
    int i;

    printf("Enter The number Under TEN: ");
    scanf("%d" , &i);
    do {
        printf("%d ", i);
        i++;
    } while (i <= 10);
    return 0;
}

#include <stdio.h>

int main() {
    int i, j;
    int height;

    printf("Enter the height of the Pyramid: ");
    scanf("%d", &height);

    for (i = 0; i < height; i++) {

        for (j = 0; j < height - i - 1; j++) {
            printf(" ");
        }

        for (j = 0; j < (2 * i + 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

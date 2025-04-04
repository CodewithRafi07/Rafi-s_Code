#include <stdio.h>

int main() {
    int i, j;
    int height = 5; // You can change this to adjust the size of the 'N'

    for(i = 0; i < height; i++) {
        for(j = 0; j < height; j++) {
            if(j == 0 || j == height - 1 || j == i) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}

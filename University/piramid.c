#include <stdio.h>

int main() {
    int i, j;
    int height = 5; // Height of the pyramid (can be adjusted)

    // Print the pyramid
    for(i = 0; i < height; i++) {
        // Print leading spaces
        for(j = 0; j < (height - i - 1); j++) {
            printf(" ");
        }
        // Print stars for the pyramid
        for(j = 0; j < (2 * i + 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

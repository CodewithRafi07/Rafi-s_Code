#include <stdio.h>

int main() {
    int i, j;
    int height = 5; // Height of the inverted pyramid (can be adjusted)

    // Print the inverted pyramid
    for(i = 0; i < height; i++) {
        // Print leading spaces
        for(j = 0; j < i; j++) {
            printf(" ");
        }
        // Print stars for the inverted pyramid
        for(j = 0; j < (2 * (height - i) - 1); j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

#include <stdio.h>

int main() {
    int i, j;
    int height = 5; // Height of the triangle (can be adjusted)

    // Print the triangle
    for(i = 0; i < height; i++) {
        // Print stars for the triangle
        for(j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

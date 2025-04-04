#include <stdio.h>

int main() {
    int i, j;

    for (i = 0; i < 7; i++) {  // 7 rows
        for (j = 0; j < 5; j++) {  // 5 columns
            if (j == 0 || (i == 0 && j < 4) || (i == 3 && j < 4) || (j == 4 && i > 0 && i < 3) || (i - j == 2)) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");  // Move to next line
    }

    return 0;
}

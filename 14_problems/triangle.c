#include <stdio.h>

int main() {
    int i, j;
    int height = 4;

    
    for(i = 0; i < height; i++) {
         
        for(j = 0; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

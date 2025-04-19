#include <stdio.h>

int main() {
    int i, j;
    int height;
    printf("Enter the hight of the Piramid: ");
    scanf("%d" , &height); 
    
    for(i = 0; i < height; i++) {

        for(j = 0; j < i; j++) {
            printf(" ");
        }
        
        for(j = 0; j < (2 * (height - i) - 1); j++) {
            printf("*");
        }
        printf("/n");
    }

    return 0;
}

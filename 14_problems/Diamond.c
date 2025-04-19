#include <stdio.h>

int main() {
    int i, Row;
    int height;
    printf("Enter the hight of the Diamond: ");
    scanf("%d" , &height);

    for(i = 0; i < height; i++) {

        for(Row = 0; Row < (height - i - 1); Row++) {
            printf(" ");
        }
        for(Row = 0; Row < (2 * i + 1); Row++) {
            printf("*");
        }
        printf("\n");
    }

    for(i = 0; i < height; i++) {

        for(Row = 0; Row < i; Row++) {
            printf(" ");
        } 
        for(Row = 0; Row < (2 * (height - i) - 1); Row++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}

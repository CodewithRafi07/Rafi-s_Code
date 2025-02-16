#include <stdio.h>

int main(){
    for (int i = 0; i < 21; i++)
    {
        if (i==9){
            //break; // exit the loop now!
            continue; // skip the iteration now!
        }
        printf("I is %d\n" , i);
    }
    printf("For loop is done");
    
    return 0;
}
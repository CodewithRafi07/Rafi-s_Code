#include <stdio.h>

int main(){
    int a = 134, b = 160;
    a=a-b;
    b=a+b;
    a=b-a;
    printf("The swap number is a=%d\n Another swap number is b=%d\n" , a , b);
    return 0;
}
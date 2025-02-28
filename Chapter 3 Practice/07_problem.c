#include <stdio.h>

int main(){
    int a, b, c, d;
    printf("Enter a: \n");
    scanf("%d" , &a);

    printf("Enter b: \n");
    scanf("%d" , &b);

    printf("Enter c: \n");
    scanf("%d" , &c);
    
    printf("Enter d: \n");
    scanf("%d" , &d);

    if(a>b && a>c && a>d){
        printf("The greteast of all is %d", a);
    }
         else if(b>a && b>c && b>d){
        printf("The greteast of all is %d", b);
    }
         else if(c>a && c>b && c>d){
        printf("The greteast of all is %d", c);
    }
         else if(d>a && d>c && d>b){
        printf("The greteast of all is %d", d);
    }

     return 0;
}
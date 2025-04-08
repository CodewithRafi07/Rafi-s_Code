/*Write same code many times solution
Resuse a programme
*/ 

#include <stdio.h>

// Function Prototype

int sum(int , int);

// Function Defenation

int sum(int x , int y){
    printf("The Sum is %d\n" , x + y);
    return x + y;
}

int main(){
    
    int a = 1;
    int b = 2;

    //int c = a + b;
    //printf("The sum is %d\n" , c);

    sum (a, b); // Function Call

    /* int c = sum (a , b); // Its also Function Call
    printf ("%d" , c);*/
     

    int a1 = 12;
    int b1 = 22;

    //int c1 = a1 + b1;
    //printf("The sum is %d\n" , c1);

    sum (a1 , b1); // Function Call

    int a2 = 15;
    int b2 = 25;

    //int c2 = a2 + b2;
    //printf("The sum is %d\n" , c2);

    sum (a2, b2); // Function Call

    return 0;
}
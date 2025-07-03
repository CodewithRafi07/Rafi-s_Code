#include <stdio.h>

int factorial (int);
//factorial(5) = 1 x 2 x 3 x 4 x 5
//factorial(4) = 1 x 2 x 3 x 4 
//factorial(3) = 1 x 2 x 3
//factorial(n) = 1 x 2 x 3 x ..... x n-1 x n
//factorial(n-1) = 1 x 2 x 3 x ....x n-1
//factorial(n) = factorial(n-1) x n

int factorial(int n){
     if (n == 1 || n == 0){ // Base Condition
        return 1;
}
return factorial(n-1) * n;
}

int main(){
    int a = 3;
    printf("The factorial of %d is %d" , a , factorial(a));

    return 0;
}
//code is correct
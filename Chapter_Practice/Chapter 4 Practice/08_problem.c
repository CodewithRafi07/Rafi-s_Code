
// factorial
/*8! = 1 X 2 X 3 X 4 X 5 X 6 X 7 X 8
5! = 1 X 2 X 3 X 4 X 5
n! = 1 X 2 X 3 X 4 X 5 X 6 X ......
0! = 1 */

#include <stdio.h>\

int main(){
    int product=1;
    int n;
    printf("Enter the n:");
    scanf("%d" , &n);

    for (int i = 1; i <= n; i++)
    {
        product = product * i;
    }

    printf("The factorial is %d" , product);
    

    return 0;
}
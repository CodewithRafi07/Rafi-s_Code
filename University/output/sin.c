#include<stdio.h>
int main( ) { 

    int number, guess;
 
     srand(time(NULL));
     number=rand( ) %10+1;
    
     printf("guess a number between 1 and 10:");
     scanf("%d", &guess);

if (guess== number){
   printf("congratulations,Sinthila!you guessed it");
}
else{
   printf("better luck next time!the number was%d\n",number);

}
 return 0;
}
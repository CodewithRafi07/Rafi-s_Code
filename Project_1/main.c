#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Seed the random number generator
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomnumber = (rand() % 100) + 1;

    // Print the random number
    // printf("Random Number: %d\n", randomNumber);

    int no_of_guesses = 0;
    int guessed;

    do
    {
        printf("Guess the number: ");
        scanf("%d", &guessed);
       
        if (guessed>randomnumber)
        {
            printf("Lower Number Please\n");
        }
        else if (guessed<randomnumber)
        {
            printf("Higher Number Please\n");
        }
        else {
            printf("Congratulation!\n");
        }
        no_of_guesses++;
        
        
    } while (guessed != randomnumber);

    printf("You guessed the number in %d guessess", no_of_guesses);

    return 0;
}

// Job checking with ternary

#include <stdio.h>

int main() {
    int experience, interview_score;

    printf("Enter your years of experience: ");
    scanf("%d", &experience);
    
    printf("Enter your interview score: ");
    scanf("%d", &interview_score);

    (experience >= 3 && interview_score >= 60) ? printf("Congratulations! You got the job.\n") : printf("Sorry, you didn't get the job.\n");

    return 0;
}

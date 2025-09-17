#include <stdio.h>
#include <stdlib.h>

int main()
{
    const int secretnumber = 5;
    int guess = 0;
    int guesscount = 0;
    const int guesslimit = 3;

    while (guess != secretnumber && guesscount < guesslimit)
    {
        printf("Enter a number: ");
        scanf("%d", &guess);
        guesscount++;
        if (guess != secretnumber)
        {
            printf("Wrong number, try again\n");
        }
    }

    if (guess == secretnumber)
    {
        printf("You Win!\n");
    }
    else
    {
        printf("You are out of guesses\n");
    }
}
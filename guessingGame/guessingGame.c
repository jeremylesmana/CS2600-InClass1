#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int userSelection, correctNumber;
    int maxNumber = 10;
    char userGuess;

    time_t t; //Initializing time for random generation
    srand((unsigned) time(&t));
   
    menu:
    printf("Press 1 to play game\nPress 2 to change the max number\nPress 3 to quit\n");
    scanf("%d", &userSelection);

    switch(userSelection) {
        case 1:
            goto game;
            break;
        case 2:
            goto maxNumber;
            break;
        case 3: 
            goto quit;
            break;
        default:
            goto menu;
            break;
    }

    game: 
    correctNumber = (rand() % maxNumber) + 1; //Generate a random number from 0 - max value
    printf("Enter a number: ");
    scanf("%c", &userGuess);
    
    if (userGuess == 'q')
        goto menu;

    while((int)userGuess != (int)correctNumber) {
        if ((int)userGuess > (int)correctNumber) {
            printf("Your guess is too high, enter another number:");
            scanf("%d", &userGuess);
        }
        else{
            printf("Your guess is too low, enter another number:");
            scanf("%d", &userGuess);
        }
    }
    printf("Your guess is correct! Going back to main menu");
    goto menu;

    maxNumber:
    quit:
    printf("Thank you for playing!");
}
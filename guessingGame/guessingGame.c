#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* 
Jeremy Lesmana

First I'm going to initialize all my variables. I'm going to keep the userGuess variable
as a string because it should be able to accept "q" and return the user back to the main menu.

When the program first starts, it's going to again hpave the time_t for the time and 
do srandom with the time as the seed for a more "random" generation.
The menu is then going to popout with the scanf for the user to enter their selection.
A switch statement is then going to compare the answer and jump to their section respectively.

During game phase:
    In the game phase, the random number is already generated and it will ask the user to input
    a number. If that number is lower or higher it will say; and if the user gets it right, it will
    congratulate them and return them back to menu. Here we take the "atoi" function because the
    guesses will be inputted as a string, and if it's not a "q", it will get converted to an integer
    in which we can compare with the actual correct number. If it is a "q", it will return the user
    back to the main menu

During setting max number phase:
    Setting the max number allows the user to change the maxNumber variable that I have initialized in
    the very start that started off as 10. The user can only input a number between 1-10 and cannot 
    input any negative numbers or anything above the "max" value which is 10 in this case.

During quit phase:
    The program will just printf a thank you message and the program will end there.

*/
int main() {
    int correctNumber, userSelection, userMaxNumber, checkQ; //Setting initial variables
    int maxNumber = 10;
    char userGuess[5];

    time_t t; //Initializing time for random generation
    srand((unsigned) time(&t));
   
    menu:
    printf("\nPress 1 to play game\nPress 2 to change the max number\nPress 3 to quit\n"); //Prompt user the menu
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
    scanf("%s", &userGuess); //We scan it as a string in case it is a 'q'

    checkQ = strcmp((userGuess), "q");
    if (checkQ == 0) { //If the guess is a 'q', we're taking them back to the main menu.
        goto menu;
    }

    while(atoi(userGuess) != correctNumber) {
        if (atoi(userGuess) > correctNumber) { //Checks if the guesses are too high or too low and will print to them respectively.
            printf("Your guess is too high, enter another number:");
            scanf("%s", &userGuess);
        }
        else{
            printf("Your guess is too low, enter another number:");
            scanf("%s", &userGuess);
        }
    }
    printf("Your guess is correct! Going back to main menu");
    goto menu;

    maxNumber:
    printf("Enter your max number (must be non-negative and between 1-10): ");
    scanf("%d", &userMaxNumber);
    while(userMaxNumber < 1 || userMaxNumber > 10){ //If the user's entered max number isn't within the range, keep them on a loop until they obey.
        printf("Please enter a valid number! Try again: ");
        scanf("%d", &userMaxNumber);
    }
    maxNumber = userMaxNumber;
    printf("Successfully changed the max number!");
    goto menu;

    quit:
    printf("Thank you for playing!"); //Thank you message to end it off.
}
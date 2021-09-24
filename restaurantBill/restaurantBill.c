#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    float taxPercentage, tipPercentage, menuPrice; //Initializing variables for tax and tip percentage
    time_t t; //Initializing time for random generation
    srand((unsigned) time(&t));
    int menuItem = rand() % 4; //Generate a random number from 0-3 for menu items.
    
    printf("Enter tax percentage:"); //Ask user for tax percentage
    scanf("%f", &taxPercentage);
    printf("Enter tip percentage:"); //Ask user for tip percentage
    scanf("%f", &tipPercentage);

    switch(menuItem) { //Switch case for different types of menu items
        case 0:
            printf("You had the salad, costing $9.95");
            menuPrice = 9.95;
            break;
        case 1:
            printf("You had the soup, costing $4.55");
            menuPrice = 4.55;
            break;
        case 2:
            printf("You had the sandwich, costing $13.25");
            menuPrice = 13.25;
            break;
        case 3:
            printf("You had the pizza, costing $22.35");
            menuPrice = 22.35;
            break;
    }
    float taxAmount, tipAmount, totalAmount; //Initialize amount variables
    
    taxAmount = menuPrice * 0.01 * taxPercentage; //Calculating tax amount
    printf("\nYour tax amount is: $%.2f\n", taxAmount);
    tipAmount = menuPrice * 0.01 * tipPercentage; //Calculating tip amount
    printf("Your tip amount is: $%.2f\n", tipAmount);

    totalAmount = menuPrice + taxAmount + tipAmount;
    printf("Your total bill comes out to: $%.2f\n", totalAmount);
}
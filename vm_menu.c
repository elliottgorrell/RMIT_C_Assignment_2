/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "vm_menu.h"

/**
 * vm_menu.c handles the initialisation and management of the menu array.
 **/

/**
 * In this function you need to initialise the array of menu items
 * according to the text to be displayed for the menu. This array is
 * an array of MenuItem with text and a pointer to the function
 * that will be called.
 **/
void initMenu(MenuItem * menu)
{

}

/**
 * Gets input from the user and returns a pointer to the MenuFunction
 * that defines how to perform the user's selection. NULL is returned
 * if an invalid option is entered.
 **/
MenuFunction getMenuChoice(MenuItem * menu)
{
    return NULL;
}

void displayMenu() {
    printf("Main Menu:\n");
    printf("1.Display Items\n");
    printf("2.Purchase Items\n");
    printf("3.Save and Exit\n");
    printf("Administrator-Only Menu:\n");
    printf("4.Add Item\n");
    printf("5.Remove Item\n");
    printf("6.Display Coins\n");
    printf("7.Reset Stock\n");
    printf("8.Reset Coins\n");
    printf("9.Abort Program\n");
    printf("Select your option (1-9):\n");
}

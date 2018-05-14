/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "vm_options.h"

/**
 * vm_options.c this is where you need to implement the system handling
 * functions (e.g., init, free, load, save) and the main options for
 * your program. You may however have some of the actual work done
 * in functions defined elsewhere.
 **/

/**
 * Initialise the system to a known safe state. Look at the structure
 * defined in vm_system.h.
 **/
Boolean systemInit(VmSystem * system)
{
    return FALSE;
}

/**
 * Free all memory that has been allocated. If you are struggling to
 * find all your memory leaks, compile your program with the -g flag
 * and run it through valgrind.
 **/
void systemFree(VmSystem * system)
{ }

/**
 * Loads the stock and coin data into the system. You will also need to assign
 * the char pointers to the stock and coin file names in the system here so
 * that the same files will be used for saving. A key part of this function is
 * validation. A substantial number of marks are allocated to this function.
 **/
Boolean loadData(VmSystem * system, const char * stockFileName, const char * coinsFileName)
{
    if ( !loadStockData(system, stockFileName) ){
        printf("Error: Couldn't load stock");
        return FALSE;
    };
    return TRUE;
}

/**
 * Loads the stock file data into the system.
 **/
Boolean loadStock(VmSystem * system, const char * fileName)
{
    return FALSE;
}

/**
 * Loads the coin file data into the system.
 **/
Boolean loadCoins(VmSystem * system, const char * fileName)
{
    return FALSE;
}

/**
 * Saves all the stock back to the stock file.
 **/
Boolean saveStock(VmSystem * system)
{
    return FALSE;
}

/**
 * Saves all the coins back to the coins file.
 **/
Boolean saveCoins(VmSystem * system)
{
    return FALSE;
}

/**
 * This option allows the user to display the items in the system.
 * This is the data loaded into the linked list in the requirement 2.
 **/
void displayItems(VmSystem * system)
{
    Node * currNode = system->itemList->head;

    printf(" %-8s| %-25s| %-15s| %-10s\n", "ID", "Name", "Available", "Price");
    for (int i=0; i < 60; i++) printf("-");
    printf("\n");
    while(currNode != NULL) {
        printf(" %-8s| %-25s| %-15u| $%u.%u\n", currNode->data->id,currNode->data->name, currNode->data->onHand, currNode->data->price.dollars, currNode->data->price.cents);
        currNode = currNode->next;
    }
 }

/**
 * This option allows the user to purchase an item.
 * This function implements requirement 5 of the assignment specification.
 **/
void purchaseItem(VmSystem * system)
{
    char buffer[25];
    char id[10];
    unsigned int insertedMoney = 0;
    Stock* item = NULL;
    unsigned int requiredMoney;
    unsigned int totalInsertedMoney = 0;

    while (item == NULL){
        printf("Please enter the id of the item you wish to purchase: ");
        fgets(buffer,25,stdin);

        if(strcspn(buffer, "\r\n") >= strlen(buffer)){
            readRestOfLine();
        }

        if( buffer[0] == '\n') return;
        
        strncpy(id, buffer, 10);

        // Convert to null terminated string so getItemById strcmp() will work
        id[strcspn(id, "\r\n")] = '\0';

        item = getItemById(system, &id);
    }

    printf("You have selected \"%s\". This will cost you $%u.%u\n", item->desc, item->price.dollars, item->price.cents);
    printf("Please hand over the money – type in the value of each note/coin in cents.\n");
    printf("Press enter on a new and empty line to cancel this purchase:\n");

    requiredMoney = (item->price.dollars*100) + (item->price.cents);
    while (totalInsertedMoney < requiredMoney) {
        printf("You still need to give us %u: ", (requiredMoney - totalInsertedMoney));
        fgets(buffer,25,stdin);
        if(strcspn(buffer, "\r\n") >= strlen(buffer)){
            readRestOfLine();
        }

        if( buffer[0] == '\n') return;

        char *chk;
        insertedMoney = (int) strtol(buffer, &chk, 10);
        if (!isspace(*chk) && *chk != 0)
            printf("Not a valid amount of money\n", buffer);

        totalInsertedMoney += insertedMoney;
        insertedMoney = 0;
    }

    printf("Thank you. Here is your %s, and your change of %u.\n", item->name, (totalInsertedMoney - requiredMoney));
    printf("Please come back soon.\n");


}

/**
 * You must save all data to the data files that were provided on the command
 * line when the program loaded up, display goodbye and free the system.
 * This function implements requirement 6 of the assignment specification.
 **/
void saveAndExit(VmSystem * system)
{ }

/**
 * This option adds an item to the system. This function implements
 * requirement 7 of of assignment specification.
 **/
void addItem(VmSystem * system)
{ }

/**
 * Remove an item from the system, including free'ing its memory.
 * This function implements requirement 8 of the assignment specification.
 **/
void removeItem(VmSystem * system)
{ }

/**
 * This option will require you to display the coins from lowest to highest
 * value and the counts of coins should be correctly aligned.
 * This function implements part 4 of requirement 18 in the assignment
 * specifications.
 **/
void displayCoins(VmSystem * system)
{ }

/**
 * This option will require you to iterate over every stock in the
 * list and set its onHand count to the default value specified in
 * the startup code.
 * This function implements requirement 9 of the assignment specification.
 **/
void resetStock(VmSystem * system)
{ }

/**
 * This option will require you to iterate over every coin in the coin
 * list and set its 'count' to the default value specified in the
 * startup code.
 * This requirement implements part 3 of requirement 18 in the
 * assignment specifications.
 **/
void resetCoins(VmSystem * system)
{ }

/**
 * This option will require you to display goodbye and free the system.
 * This function implements requirement 10 of the assignment specification.
 **/
void abortProgram(VmSystem * system)
{ }

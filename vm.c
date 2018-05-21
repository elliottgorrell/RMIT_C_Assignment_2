/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "vm.h"

int main(int argc, char ** argv)
{
    Boolean running = TRUE;
    int choice = 0;
    char buffer[2];
    size_t length;
    VmSystem system;

    if(argc == 1) {
        printf("Error: You must provide a file to load\n");
        return EXIT_FAILURE;
    }
    else if(argc > 2 ) {
        printf("Error: You only need to provide one argument\n");
        return EXIT_FAILURE;
    }

    loadData(&system,argv[1],"blah");

    while ( running ){
        displayMenu();

        fgets(buffer,2,stdin);
        sscanf(buffer, "%d", &choice);

        if(strcspn(buffer, "\r\n") >= strlen(buffer)){
            readRestOfLine();
        }

        switch(choice){
            case 1:
                displayItems(&system);
                break;
            case 2:
                purchaseItem(&system);
                break;
            case 3:
                saveAndExit(&system);
                running = FALSE;
                break;
            case 4:
                addItem(&system);
                break;
            case 9:
                running = FALSE;
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }


    }

    return EXIT_SUCCESS;
}


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
    char buffer[5];
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

        fgets(buffer,5,stdin);
        sscanf(buffer, "%d", &choice);

        switch(choice){
            case 1:
                displayItems(&system);
        }


    }

    return EXIT_SUCCESS;
}


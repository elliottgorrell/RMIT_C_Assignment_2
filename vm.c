/******************************************************************************
** Student name: 	...
** Student number: 	...
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "vm.h"

int main(int argc, char ** argv)
{
    if(argc == 1) {
        printf("you must provide a file to load\n");
    }
    else if(argc > 2 ) {
        printf("we only need one argument parsed\n");
    }

    printf("you gave %i args\n",(argc-1));
    printf("Goodbye. \n\n");



    return EXIT_SUCCESS;
}
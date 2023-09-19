#include <stdio.h>
#include <stdlib.h>
#include "interactive.h"

int main(int argc, char* argv[]){
    // first input the arguments to the function. This will decide if the user wants interactive mode 
    // or batch mode.

    if (argc == 1){
        interactiveMode();
    }

    else if(argc == 2){
        //batchMode();
        // delete line after test
        printf("Batch Mode");
    }
    else{
        // revisit to set it up to the standard error.
        printf("Error");
    }

    return EXIT_SUCCESS;
}
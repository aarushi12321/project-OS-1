// This is the c program to parse any string, both in interactive and batch mode,
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* parseFn(char* inpStr){
    // get the input from the user and parse the string to get the command and its arguments.
    // Assume, for now that there is only one command. Later, modify this to implement many commands
    // at the same time.

    // modify the return type to the array of struct that should be created later that contains the
    // commands and the arguments.

    // to track the position of the input string
    char* cmdBuffer;
    // custom separator
    char* sep = " ";
    // token from strtok_r function
    char* token = strtok_r(inpStr, sep, &cmdBuffer);
    while(token){
        // remove printf and check the input. Store it to a static array. If it is exit, cd or path go 
        // to the default commands  else go to the commands specified in the paths that will be specified.
        printf("%s ", token);
        // passed NULL to continue parsing the same sentence.
        token = strtok_r(NULL, sep, &cmdBuffer);
    }

    // change return type. Only to test.
    return " ";
}
// This is the c program to parse any string, both in interactive and batch mode,
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "defs.h"

instruction* parseFn(char* inpStr){
    // get the input from the user and parse the string to get the command and its arguments.
    // Assume, for now that there is only one command. Later, modify this to implement many commands
    // at the same time.

    // modify the return type to the array of struct that should be created later that contains the
    // commands and the arguments.

    // define an instruction struct
    instruction* inst = (instruction*) malloc(sizeof(instruction));
    // set the number of arguments to 0.
    inst->nArguments = 0;
    inst->arguments = NULL;

    // to track the position of the input string
    char* cmdBuffer;
    // custom separator
    char* sep = " ";
    // token from strtok_r function
    char* token = strtok_r(inpStr, "\n", &cmdBuffer);

    token = strtok_r(inpStr, sep, &cmdBuffer);

    // first token is the name of the instruction
    inst->name = (char*)malloc((strlen(token) + 1) * sizeof(char));
    strcpy(inst->name, token);

    while(token){
        // Check the input. Store it to a static array. If it is exit, cd or path go 
        // to the default commands  else go to the commands specified in the paths that will be specified.
        
        // passed NULL to continue parsing the same sentence.
        token = strtok_r(NULL, sep, &cmdBuffer);
        // add the arguments to the arguments array in the instuction struct.

        // if token is not null then 
        if (token){
            inst->arguments = (char**) realloc (inst->arguments, (inst->nArguments+1)*sizeof(char*));
            inst->arguments[inst->nArguments] = (char*) malloc ((strlen(token) + 1) * sizeof(char));
            strcpy(inst->arguments[inst->nArguments], token);
            inst->nArguments++;
        }
    }

    // change return type. Only to test.
    return inst;
}
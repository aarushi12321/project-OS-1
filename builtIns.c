// this file is to define and check for built in functions. If not a built in function,
// it checks whether these files are available in paths specified.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "defs.h"

// list of built in commands
char* builtInInstructions[] = {"cd", "exit", "path"};

// function that takes in instruction pointer and returns an int
// that indicates the status of execution of this built in command.
int built_cd(instruction* inst){
    // if the cd command does not have a path, return null.
    if (inst->arguments[0] == NULL){
        perror("Error 1.");
    }
    // if it fails to change directory, return -1 else it returns 0.
    else if (chdir(inst->arguments[0])!=0){
            perror("Error 2.");
        }
    // on successful completion, return 1.
    return 1;
}

int built_exit(instruction* inst){
    // exit out of the shell.
    exit(0);
};

void checkInstruction(instruction* inst){
    printf("%s", inst->name);
    // if the instruction is cd

    // comparing if the strings are equal
    // not changing directory
    if (strcmp(inst->name, "cd")==0){
        int res = built_cd(inst);
    }

    // not exiting
    else if (strcmp(inst->name, "exit")==0){
        int res = built_exit(inst);
    }
    else{
        printf("Find in path\n");
    }

    return;
};
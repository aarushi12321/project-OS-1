// this file is to define and check for built in functions. If not a built in function,
// it checks whether these files are available in paths specified.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "defs.h"

// declared as global vars
char* defaultPaths[] = {"/bin", "/usr/bin"};
char** paths=defaultPaths;
int nPaths = 2;

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

// function that takes in instruction pointer and returns an int
// that indicates the status of execution of this built in command.
int built_exit(instruction* inst){
    // exit out of the shell.
    exit(0);
};

// function that takes in instruction pointer and returns a pointer to an array of strings
// that indicates the status of execution of this built in command.
char** built_path(instruction* inst, int* ptrPaths){
    // initialize an array that is of the size of the number of arguments
    // in the instruction struct. These are the number of paths that are 
    // to be used because everytime we set them from scratch.
    
    // initialize the array paths
    char** paths=NULL;
    for(int i=0; i < inst->nArguments; i++){
        // reallocate memory for the paths array
        paths = (char**) realloc (paths, (i+1)*sizeof(char*));
        // allocate memory for the string that will be input
        paths[i] = (char*) malloc ((strlen(inst->arguments[i]) + 1)*sizeof(char));
        // copy the argument to path
        strcpy(paths[i], inst->arguments[i]);
    }

    *ptrPaths = inst->nArguments;

    return paths;
};

void forkAndExec(char* finalPath){
    printf("%s\n", finalPath);
    return;
};

void checkInstruction(instruction* inst){
    // by default set them to default path values

    // if the instruction is cd
    // comparing if the strings are equal
    if (strcmp(inst->name, "cd")==0){
        int res = built_cd(inst);
    }

    // to exit from the shell
    else if (strcmp(inst->name, "exit")==0){
        int res = built_exit(inst);
    }

    // add path to the existing paths
    else if (strcmp(inst->name, "path")==0){
        paths = built_path(inst, &nPaths);
        if(!paths){
            perror("Could not add paths.");
        }
    }

    // except the aforementioned built in commands, now we use commands that
    // will be custom called by concatenating it to the mentioned paths.
    else{
        // check if the command exists in the mentioned paths
        // also, additionally check if the user has mentioned absolute path for the command.

        // construct the command
        int totalLen = 0;
        totalLen += strlen(inst->name)+1;
        for(int i=0; i< inst->nArguments; i++){
            // for the space
            totalLen += strlen(inst->arguments[i]) + 1;
        }

        // allocate the memory
        char* command = malloc((totalLen+1)*sizeof(char));
        
        // reconstruct the command
        strcpy(command, inst->name);

        for(int i=0; i< inst->nArguments; i++){
            strcat(command, " ");
            strcat(command, inst->arguments[i]);
        }

        // create the command
        char* finalPath;
        int checkpathLen = 0;
        int pathLen = 0;
        int found = 0;
        
        for(int i=0; i<nPaths; i++){
            checkpathLen += strlen(paths[i]);
            checkpathLen += strlen(inst->name);

            char* checkPath = malloc((checkpathLen+2)*sizeof(char));
            strcpy(checkPath, paths[i]);
            strcat(checkPath, "/");
            strcat(checkPath,inst->name);

            // check if it exists in path. If yes, break. Else see in the paths
            // mentioned by the user/ other default paths

            // path found
            if(access(checkPath, X_OK) == 0){
                found = 1;

                pathLen += strlen(paths[i]) + strlen(command);
                char* finalPath = malloc((pathLen+2)*sizeof(char));
                strcpy(finalPath, paths[i]);
                strcat(finalPath, "/");
                strcat(finalPath,command);

                // call fork and exec
                forkAndExec(finalPath);
                break;
            }
            // if it does concat path with command and send to execute
            // else show error
        }

        if(found==0){
            perror("No such command.");
        }
    }
    return;
};
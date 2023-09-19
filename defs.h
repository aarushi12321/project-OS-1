#ifndef DEFS_H
#define DEFS_H

// define a structure that stores the instruction in a structured manner and return this from the parse function.
typedef struct instruction{
    char* name;
    char** arguments;
    int nArguments;
    int redirection;
    char* outfile;
}instruction;
#endif 
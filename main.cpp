/*******************************************************
* Name:        Jory Ehman
 * Course:      Program Translation / Compilers
 * Project:     P1
 * File:        main.cpp
 * Description:
 *   Entry point of the program. Handles command-line
 *   argument validation (P0 discipline), opens input
 *   file or uses standard input, invokes tree
 *   construction, performs all required traversals,
 *   and ensures proper memory cleanup before exit.
 *
 *   This file coordinates all modules but does not
 *   implement tree logic directly.
 *******************************************************/
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "node.h"
#include "buildTree.h"
#include "traversals.h"

int main(int argc, char* argv[]){

    FILE* file = NULL;
    //Base name buffer (this must persist for traversal calls)
    char baseNameBuffer[256];
    const char* baseName = NULL;

    if (argc == 1){
        file = stdin;
        strcpy(baseNameBuffer, "out");
        baseName = baseNameBuffer;
    }
    else if (argc == 2){

        file = fopen(argv[1], "r");

        if (file == NULL){
            fprintf(stderr, "Fatal: Cannot open file\n");
            exit(EXIT_FAILURE);
        }

        strncpy(baseNameBuffer, argv[1], sizeof(baseNameBuffer));
        baseNameBuffer[sizeof(baseNameBuffer) - 1] = '\0';

        //Strip the extension if possible
        char* dot = strrchr(baseNameBuffer, '.');
        if (dot != NULL){
            *dot = '\0';
        }
        baseName = baseNameBuffer;
    }
    else {
        fprintf(stderr, "Fatal: Improper usage\n");
        fprintf(stderr, "Usage: P1 [filename]\n");
        exit(EXIT_FAILURE);
    }

    node_t* root = buildTree(file);

    //close the file if not stdin
    if (file != stdin){
        fclose(file);
    }

    //check for missing data
    if (root == NULL){
        fprintf(stderr, "Error: missing data\n");
        exit(EXIT_FAILURE);
    }

    //perform traversals
    traversePreOrder(root, baseName);
    traverseLevelOrder(root, baseName);
    traversePostOrder(root, baseName);

    //Calls deletion constructor to free memory
    delete(root);

    return 0;
}
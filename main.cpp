//
// Created by Jory on 2/13/2026.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "node.h"
#include "buildTree.h"
#include "traversals.h"

int main(int argc, char* argv[]){

    FILE* file = NULL;
    const char* baseName = NULL;

    if (argc == 1){
        file = stdin;
        baseName = "out";
    }
    else if (argc == 2){

        file = fopen(argv[1], "r");

        if (file == NULL){
            fprintf(stderr, "Fatal: Cannot open file\n");
            exit(EXIT_FAILURE);
        }

        baseName = argv[1];
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
    traverseLevelOrder(root, baseName);
    traversePreOrder(root, baseName);
    traversePostOrder(root, baseName);

    return 0;
}
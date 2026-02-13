//
// Created by Jory on 2/13/2026.
//

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cctype>

#include "buildTree.h"
#include "node.h"

//Static helper function prototypes (internal linkage only)
static node_t* insert(node_t* root, const std::string& str);
static bool isValidChar(char c);
static bool isValidString(const std::string& s);

/*
buildTree:
Reads input from FILE*, validates Tokens, inserts into BST, and returns root.
 */

node_t* buildTree(FILE* file){
   node_t* root = NULL;

   char buffer[1024]; //sets buffer size

   //we allow 1023+null terminator character when scanning to ensure buffer is not overflowed
   while(fscanf(file, "%1023s", buffer) == 1){
       std::string token(buffer);

       if (!isValidString(token)){
           fprintf(stderr, "Error: Invalid character encountered\n");
           exit(EXIT_FAILURE);
       }

       root = insert(root, token);
   }

   return root;
}

/*
insert:
Inserts string into BST based on ASCII Key
 */
static node_t* insert(node_t* root, const std::string& str){
    //TODO: Implement BST insertion logic
    return root;
}

/*
isValidString:
Checks if entire string contains only allowed characters
 */
static bool isValidString(const std::string& ss){
    //TODO: Loop through characters and validate
    return true;
}

static bool isValidChar(char c){
    //TODO: Implement allowed character logic
    return true;
}
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

After each insertion:
    Left subtree keys < root key
    Right subtree keys > root key
    Each node's strings all share same first character
 */
static node_t* insert(node_t* root, const std::string& str){
    int key = static_cast<int>(str[0]); //Computes key from ascii of first character

    //base case: if we've found where the node belongs, create a new node, store the string, return pointer to the node
    if (root == NULL){
        node_t* newNode = new node_t(key);
        newNode -> strings.push_back(str);
        return newNode;
    }

    //go left: recursively
    if (key < root -> key){
        root -> left = insert(root -> left, str);
    }

    //go right: recursively
    else if (key > root -> key){
        root -> right = insert(root -> right, str);
    }

    //Equal key -> add to existing node's bucket
    //Preserves bucket invariant
    else {
        root -> strings.push_back(str);
    }

    //always return subtree root (pointer)
    return root;
}

/*
isValidString:
Checks if entire string contains only allowed characters
 */
static bool isValidString(const std::string& s){
    for (char c: s){
        if (!isValidChar(c)){
            return false;
        }
    }
    return true;
}

static bool isValidChar(char c){
    //we cast to unsigned char because isalpha() and isdigit() expect an unsigned char. Passing
    //negative char values is undefined behavior
    unsigned char uc = static_cast<unsigned char>(c);

    if (std::isalpha(uc))
        return true;

    if (std::isdigit(uc))
        return true;

    if (uc >= 33 && uc <= 47)
        return true;

    return false;
}
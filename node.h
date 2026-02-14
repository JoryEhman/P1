/*******************************************************
* Name:        Jory Ehman
 * Course:      Program Translation / Compilers
 * Project:     P1
 * File:        node.h
 * Description:
 *   Defines the node_t structure used to implement
 *   the binary search tree. Each node stores:
 *     - ASCII key (based on first character)
 *     - Left and right child pointers
 *     - A vector of strings sharing the same key
 *
 *   This structure represents the core data model
 *   for the BST used throughout the program.
 *******************************************************/
#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

struct node_t
{
    int key;
    node_t* left;
    node_t* right;
    std::vector<std::string> strings;

    node_t(int asciiKey){
        key = asciiKey;
        left = NULL;
        right = NULL;
    }

};

#endif //NODE_H

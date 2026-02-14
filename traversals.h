/*******************************************************
* Name:        Jory Ehman
 * Course:      Program Translation / Compilers
 * Project:     P1
 * File:        traversals.h
 * Description:
 *   Declares traversal functions for the BST:
 *
 *     - Pre-order traversal
 *     - Post-order traversal
 *     - Level-order traversal
 *
 *   Each traversal writes formatted output to a file
 *   derived from the provided base filename.
 *******************************************************/
#ifndef TRAVERSALS_H
#define TRAVERSALS_H

#include "node.h"

void traverseLevelOrder(node_t* root, const char baseName[]);
void traversePreOrder(node_t* root, const char baseName[]);
void traversePostOrder(node_t* root, const char baseName[]);

#endif //TRAVERSALS_H

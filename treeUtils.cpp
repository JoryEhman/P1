/*******************************************************
* Name:        Jory Ehman
 * Course:      Program Translation / Compilers
 * Project:     P1
 * File:        treeUtils.cpp
 * Description:
 *   Implements memory cleanup utilities for the BST.
 *   Specifically provides a post-order deletion
 *   routine to safely deallocate all dynamically
 *   allocated nodes.
 *
 *   Children are deleted before parents to prevent
 *   dereferencing freed memory.
 *******************************************************/
#include "treeUtils.h"

void deleteTree(node_t* root){
   if (root == NULL)
       return;

   deleteTree(root -> left);
   deleteTree(root -> right);

   delete root;
}
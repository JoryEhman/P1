//
// Created by Jory Ehman on 2/14/26.
//
#include "treeUtils.h"

/*
deleteTree:
Frees the entire BST using post-order traversal
 */

void deleteTree(node_t* root){
   if (root == NULL)
       return;

   deleteTree(root -> left);
   deleteTree(root -> right);

   delete root;
}
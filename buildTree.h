/*******************************************************
* Name:        Jory Ehman
 * Course:      Program Translation / Compilers
 * Project:     P1
 * File:        buildTree.h
 * Description:
 *   Declares the buildTree function responsible for
 *   constructing the binary search tree from validated
 *   input. The tree is ordered by ASCII value of the
 *   first character of each string.
 *
 *   This header exposes only the public interface for
 *   tree construction.
 *******************************************************/
#ifndef BUILDTREE_H
#define BUILDTREE_H

#include <cstdio>
#include "node.h"

node_t* buildTree(FILE* file);

#endif //BUILDTREE_H

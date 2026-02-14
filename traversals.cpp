//
// Created by Jory on 2/13/2026.
//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <utility>

#include "traversals.h"
#include "node.h"

//Static helper prototype
static void preOrderHelper(node_t* node, FILE* outFile, int depth);
static void postOrderHelper(node_t* node, FILE* outFile, int depth);

void traverseLevelOrder(node_t* root, const char baseName[]){
    if (root == NULL){
        return;
    }

    char fileName[256];
    snprintf(fileName, sizeof(fileName), "%s.levelorder", baseName);

    FILE* outFile = fopen(fileName, "w");

    if (outFile == NULL){
        fprintf(stderr, "Fatal: Cannot open output file\n");
        exit(EXIT_FAILURE);
    }

    std::queue<std::pair<node_t*, int>> q;

    q.push(std::make_pair(root, 0));

    while (!q.empty()){
        std::pair<node_t*, int> current = q.front();
        q.pop();

        node_t* node = current.first;
        int depth = current.second;

        //Indentation
        for (int i = 0; i < depth * 4; i++){
            fprintf(outFile, " ");
        }

        //print level and key
        fprintf(outFile, "%d %d ", depth, node -> key);

        for (size_t i = 0; i < node -> strings.size(); i++){
            fprintf(outFile, "%s", node -> strings[i].c_str());

            if (i < node -> strings.size() - 1){
                fprintf(outFile, " ");
            }
        }

        fprintf(outFile, "\n");

        //Push children (left first)
        if (node -> left != NULL){
            q.push(std::make_pair(node -> left, depth + 1));
        }
        if (node -> right != NULL){
            q.push(std::make_pair(node -> right, depth + 1));
        }
    }
    fclose(outFile);
}

/*
Public traversal Functions
 */
//traversePreOrder
void traversePreOrder(node_t* root, const char baseName[]){

    char fileName[256];

    snprintf(fileName, sizeof(fileName), "%s.preorder", baseName);

    FILE* outFile = fopen(fileName, "w");

    if (outFile == NULL){
        fprintf(stderr, "Fatal: Cannot open output file\n");
        exit(EXIT_FAILURE);
    }

    preOrderHelper(root, outFile, 0);

    fclose(outFile);
}

void traversePostOrder(node_t* root, const char baseName[]){
    char fileName[256];

    snprintf(fileName, sizeof(fileName), "%s.postorder", baseName);

    FILE* outFile = fopen(fileName, "w");

    if (outFile == NULL){
        fprintf(stderr, "Fatal: Cannot open output file\n");
        exit(EXIT_FAILURE);
    }

    postOrderHelper(root, outFile, 0);

    fclose(outFile);
}

/*
Static Helper Implementations
 */

static void preOrderHelper(node_t* node, FILE* outFile, int depth){
    if (node == NULL)
        return;

    //indentation: 4 spaces per depth level
    for (int i = 0; i < depth * 4; i++){
        fprintf(outFile, " ");
    }

    //Print level and ascii key
    fprintf(outFile, "%d %d ", depth, node -> key);

    //Print strings without trailing space
    for (size_t i = 0; i < node -> strings.size(); i++){
        fprintf(outFile, "%s", node -> strings[i].c_str());

        if (i < node -> strings.size() - 1){
            fprintf(outFile, " ");
        }
    }

    fprintf(outFile, "\n");

    //Recursive calls
    preOrderHelper(node -> left, outFile, depth + 1);
    preOrderHelper(node -> right, outFile, depth + 1);
}

static void postOrderHelper(node_t* node, FILE* outFile, int depth){
    if (node == NULL)
        return;

    //Recursive calls
    postOrderHelper(node -> left, outFile, depth + 1);
    postOrderHelper(node -> right, outFile, depth + 1);

    //indentation: 4 spaces per depth level
    for (int i = 0; i < depth * 4; i++){
        fprintf(outFile, " ");
    }

    //Print level and ascii key
    fprintf(outFile, "%d %d ", depth, node -> key);

    //Print strings without trailing space
    for (size_t i = 0; i < node -> strings.size(); i++){
        fprintf(outFile, "%s", node -> strings[i].c_str());

        if (i < node -> strings.size() - 1){
            fprintf(outFile, " ");
        }
    }

    fprintf(outFile, "\n");
}
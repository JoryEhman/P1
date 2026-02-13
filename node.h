//
// Created by Jory on 2/13/2026.
//

#ifndef NODE_H
#define NODE_H

#include <vector>
#include <string>

struct node_t {
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

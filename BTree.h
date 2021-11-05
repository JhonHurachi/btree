#ifndef BTREE_H
#define BTREE_H

#include "Nodo.h"

class BTree
{
    Nodo *root; //root node pointer

    int t;

public:
    // BTree class Constructor initialized as empty

    BTree(int _t)

    {

        root = nullptr;

        t = _t;
    }

    // function to traverse the tree

    void traverse()

    {
        if (root != nullptr)

            root->traverse();
    }
    // function definition of search function

    Nodo *search(int k)

    {
        return (root == nullptr) ? nullptr : root->search(k);
    }

    // A function to insert the key in the node

    void insert(int k);
    // A function that removes a new key in the BTree

    void remove(int k);
};

#endif
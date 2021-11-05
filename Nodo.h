#ifndef NODO_H
#define NODO_H

class Nodo
{
    int *key;

    int t;

    Nodo **c; // A child pointers array

    int n;

    bool leaf; // returns true if tree is empty

public:
    Nodo(int _t, bool _leaf); // Nodo class constructor

    // A function to insert a new key in the subtree rooted with non full node.

    void insertnonfull(int k);

    // A function to split the child y of this node.

    void splitchild(int i, Nodo *y);

    void traverse(); // A function to traverse the b-tree

    // A function to search the key in the b-tree

    Nodo *search(int k); // if k not found the returns NULL

    int findkey(int k); // a function to find a key in the btree

    void remove(int k);

    //A function to delete a key at idx index which is leaf

    void removefromleaf(int idx);

    // A function to delete a key at idx index which is leaf non-leaf

    void removefromnonleaf(int idx);

    int getpred(int idx);

    int getsucc(int idx);

    // A function for filling the child node in the idx index.

    void fill(int idx);

    void borrowfromprev(int idx);

    void borrowfromnext(int idx);

    // A function to merge idx child of the node next node

    void merge(int idx);

    //we will make btree friend of Nodo class so that we can access private members of this class

    friend class BTree;
};

#endif
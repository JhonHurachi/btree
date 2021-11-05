#ifndef NODO_H
#define NODO_H

class Nodo
{
    int *key;

    int t;

    Nodo **c; // Array de punteros hijo

    int n;

    bool leaf; // Devuelve true si es una hoja

public:
    Nodo(int _t, bool _leaf); // Constructor

    // Inserta una nueva llave en el nodo raiz, si el nodo no está lleno

    void insertnonfull(int k);

    // Separar el hijo "y" de su nodo

    void splitchild(int i, Nodo *y);

    void traverse(); // A function to traverse the b-tree

    // A function to search the key in the b-tree

    Nodo *search(int k); // if k not found the returns nullptr

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
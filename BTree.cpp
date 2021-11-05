#include "BTree.h"
#include "Nodo.h"

#include <iostream>

using namespace std;

// A Function to insert a key in B-Tree

void BTree::insert(int k)

{

    //check if tree is empty

    if (root == nullptr)

    {

        root = new Nodo(t, true);

        root->key[0] = k;

        root->n = 1;
    }

    else

    {

        // If root is full, then tree's height increases

        if (root->n == 2 * t - 1)

        {

            Nodo *s = new Nodo(t, false);

            // Change old root as new root's child

            s->c[0] = root;

            s->splitchild(0, root);

            int i = 0;

            if (s->key[0] < k)

                i++;

            s->c[i]->insertnonfull(k);

            root = s;
        }

        else // If root is empty,then we will call insertnonfull

            root->insertnonfull(k);
    }
}

void BTree::remove(int k)

{

    if (!root)

    {

        cout << "The tree is empty\n";

        return;
    }

    // A function Call to remove function

    root->remove(k);

    // Make the first child of the root node the new root

    //if the root node has no keys.

    //If it has a child, set root to nullptr otherwise.

    if (root->n == 0)

    {

        Nodo *tmp = root;

        //check if root has leaf

        if (root->leaf)

            root = nullptr;

        else

            root = root->c[0];

        delete tmp;
    }

    return;
}
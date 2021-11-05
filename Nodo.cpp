#include "Nodo.h"
#include <iostream>
using namespace std;

Nodo::Nodo(int t1, bool leaf1)

{

    t = t1;

    leaf = leaf1;

    // Allocate memory for max possible keys

    // and the child pointers

    key = new int[2 * t - 1];

    c = new Nodo *[2 * t];

    n = 0;
}

// A function to traverse the tree

void Nodo::traverse()

{

    int i;

    for (i = 0; i < n; i++)

    {

        if (leaf == false)

            c[i]->traverse();

        cout << " " << key[i];
    }

    if (leaf == false)

        c[i]->traverse();
}

void Nodo::insertnonfull(int k)

{

    // Initialize index as rightmost element's index

    int i = n - 1;

    if (leaf == true)

    {

        // The following loop will find the location of key

        //and move all bigger keys one place further

        while (i >= 0 && key[i] > k)

        {

            key[i + 1] = key[i];

            i--;
        }

        key[i + 1] = k;

        n = n + 1;
    }

    else // If this node is not the leaf

    {

        while (i >= 0 && key[i] > k)

            i--;

        if (c[i + 1]->n == 2 * t - 1)

        {

            splitchild(i + 1, c[i + 1]);

            if (key[i + 1] < k)

                i++;
        }

        c[i + 1]->insertnonfull(k);
    }
}

void Nodo::splitchild(int i, Nodo *y)

{

    //

    Nodo *z = new Nodo(y->t, y->leaf);

    z->n = t - 1;

    for (int j = 0; j < t - 1; j++)

        z->key[j] = y->key[j + t];

    if (y->leaf == false)

    {

        for (int j = 0; j < t; j++)

            z->c[j] = y->c[j + t];
    }

    y->n = t - 1;

    for (int j = n; j >= i + 1; j--)

        c[j + 1] = c[j];

    c[i + 1] = z;

    for (int j = n - 1; j >= i; j--)

        key[j + 1] = key[j];

    key[i] = y->key[t - 1];

    //we will increment count of keys

    n = n + 1;
}

Nodo *Nodo::search(int k)

{

    //we will search the key which is greater than

    int i = 0;

    while (i < n && k > key[i])

        i++;

    // If the key is found to be equal to k

    if (key[i] == k)

        return this;

    if (leaf == true)

        return NULL;

    return c[i]->search(k);
}

int Nodo::findkey(int k)

{

    int idx = 0;

    while (idx < n && key[idx] < k)

        ++idx;

    return idx;
}

// A function to remove the key k

void Nodo::remove(int k)

{

    int idx = findkey(k);

    // check if the key to be removed is present in this node

    if (idx < n && key[idx] == k)

    {

        if (leaf)

            removefromleaf(idx);

        else

            removefromnonleaf(idx);
    }

    else

    {

        if (leaf)

        {

            cout << "The key " << k << " is not found in the tree\n";

            return;
        }

        bool flag = ((idx == n) ? true : false);

        //If there are less than t keys in the child where the key is expected to exist

        if (c[idx]->n < t)

            fill(idx);

        //We recurse on the (idx-1)th child if the last child has been merged,

        //as it must have merged with the preceding child.

        //If not, we go back to the (idx)th child, which now contains at least t keys.

        if (flag && idx > n)

            c[idx - 1]->remove(k);

        else

            c[idx]->remove(k);
    }

    return;
}

void Nodo::removefromleaf(int idx)

{

    // a loop to shift key back

    for (int j = idx + 1; j < n; ++j)

        key[j - 1] = key[j];

    n--;

    return;
}

void Nodo::removefromnonleaf(int idx)

{

    int k = key[idx];

    //In the subtree rooted at c[idx], look for k's predecessor 'pred'.

    //if the child preceding k (C[idx]) contains at least t keys.

    //Pred should be substituted for k.

    //Delete pred in C[idx] in a recursive manner.

    if (c[idx]->n >= t)

    {

        int pred = getpred(idx);

        key[idx] = pred;

        c[idx]->remove(pred);
    }

    //Examine c[idx+1] if the child C[idx] contains less than t keys.

    //Find the k's successor 'succ' in the subtree rooted at C[idx+1]

    //and replace k with succ if C[idx+1] has at least t keys.

    //Delete succ in C[idx+1] in a recursive manner.

    else if (c[idx + 1]->n >= t)

    {

        // this getsucc function returns the successor at idx

        int succ = getsucc(idx);

        key[idx] = succ;

        c[idx + 1]->remove(succ);
    }

    //we will merge k and all of c[idx+1] into c[idx]

    //if both c[idx] and c[idx+1] have fewer than t keys.

    //2t-1 keys now reside in c[idx].

    //Remove k from c[idx] by freeing c[idx+1].

    else

    {

        merge(idx);

        c[idx]->remove(k);
    }

    return;
}

// A function to get predecessor of key[idx]

int Nodo::getpred(int idx)

{

    // Move to the rightmost node until we get to a leaf.

    Nodo *cur = c[idx];

    while (!cur->leaf)

        cur = cur->c[cur->n];

    return cur->key[cur->n - 1];
}

int Nodo::getsucc(int idx)

{

    Nodo *cur = c[idx + 1];

    while (!cur->leaf)

        cur = cur->c[0];

    // Return the first key of the leaf

    return cur->key[0];
}

void Nodo::fill(int idx)

{

    if (idx != 0 && c[idx - 1]->n >= t)

        // a function to borrow key from previous node

        borrowfromprev(idx);

    else if (idx != n && c[idx + 1]->n >= t)

        borrowfromnext(idx);

    else

    {

        if (idx != n)

            merge(idx);

        else

            merge(idx - 1);
    }

    return;
}

void Nodo::borrowfromprev(int idx)

{

    Nodo *child = c[idx];

    Nodo *sibling = c[idx - 1];

    //The parent receives the final key from C[idx-1], and key[idx-1] from

    //parent is placed as the first key in C[idx]. As a result, the sibling

    //loses one key, and the child receives one.

    for (int i = child->n - 1; i >= 0; --i)

        child->key[i + 1] = child->key[i];

    //All keys in C[idx] are moved one step forward.

    //If c[idx] isn't a leaf, advance all of its child pointers one step.

    if (!child->leaf)

    {

        for (int i = child->n; i >= 0; --i)

            child->c[i + 1] = child->c[i];
    }

    child->key[0] = key[idx - 1];

    if (!child->leaf)

        child->c[0] = sibling->c[sibling->n];

    //Shifting the key from a sibling to a parent.

    //The number of keys in the sibling is reduced as a result.

    key[idx - 1] = sibling->key[sibling->n - 1];

    child->n += 1;

    sibling->n -= 1;

    return;
}

//A function that takes a key from C[idx+1] and stores it in C[idx].

void Nodo::borrowfromnext(int idx)

{

    Nodo *child = c[idx];

    Nodo *sibling = c[idx + 1];

    child->key[(child->n)] = key[idx];

    //check if child node has a leaf node

    if (!(child->leaf))

        child->c[(child->n) + 1] = sibling->c[0];

    key[idx] = sibling->key[0];

    for (int j = 1; j < sibling->n; ++j)

        sibling->key[j - 1] = sibling->key[j];

    if (!sibling->leaf)

    {

        for (int j = 1; j <= sibling->n; ++j)

            sibling->c[j - 1] = sibling->c[j];
    }

    child->n++;

    sibling->n--;

    return;
}

//C[idx] and C[idx+1] are merged with this function.

//After merging, C[idx+1] is freed.

void Nodo::merge(int idx)

{

    Nodo *child = c[idx];

    Nodo *sibling = c[idx + 1];

    child->key[t - 1] = key[idx];

    for (int j = 0; j < sibling->n; ++j)

        child->key[j + t] = sibling->key[j];

    // Copying the child pointers from C[idx+1] to C[idx]

    if (!child->leaf)

    {

        for (int j = 0; j <= sibling->n; ++j)

            child->c[j + t] = sibling->c[j];
    }

    //To fill the gap created by shifting keys[idx] to C[idx],

    //move all keys following idx in the current node one step before.

    for (int i = idx + 1; i < n; ++i)

        key[i - 1] = key[i];

    //Moving the child pointers one step

    //before (idx+1) in the current node

    for (int j = idx + 2; j <= n; ++j)

        c[j - 1] = c[j];

    //Updating the current node's key count

    //and the child's key count

    child->n += sibling->n + 1;

    n--;

    delete (sibling);

    return;
}

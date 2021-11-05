#include "Nodo.cpp"
#include "BTree.cpp"

#include <iostream>

using namespace std;

int main()

{

    BTree tree(3);

    tree.insert(13);

    tree.insert(8);

    tree.insert(5);

    tree.insert(6);

    tree.insert(11);

    tree.insert(3);

    tree.insert(7);

    tree.insert(27);

    cout << "Traversal of the constucted tree is ";

    tree.traverse();

    int k = 6;

    if (tree.search(k) != NULL)

        cout << "\nPresent";

    else

        cout << "\nNot Present";

    k = 15;

    if (tree.search(k) != NULL)

        cout << "\nPresent";

    else

        cout << "\nNot Present";

    cout << "Traversal of tree constructed is\n";

    tree.traverse();

    cout << endl;

    tree.remove(6);

    cout << "Traversal of tree after deleting 6\n";

    tree.traverse();

    cout << endl;

    tree.remove(13);

    cout << "Traversal of tree after deleting 13\n";

    tree.traverse();

    cout << endl;

    cin.get();
    return 0;
}
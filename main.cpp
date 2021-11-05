#include "Nodo.cpp"
#include "BTree.cpp"
#include "utilities.h"

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()

{

    BTree tree(3);
    createFile();
    string texto;
    ifstream archivo;
    archivo.open("archivoTerminado.txt", ios::in);

    getline(archivo, texto);
    while (!archivo.eof())
    {
        int num = std::stoi(texto);
        cout << num << endl;
        tree.insert(num);
        getline(archivo, texto);
    }

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
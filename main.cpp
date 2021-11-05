#include "Nodo.cpp"
#include "BTree.cpp"

#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int main()

{

    BTree tree(3);
    string texto;
    ifstream archivo;
    archivo.open("archivoTerminado.txt",ios::in);
    
    getline(archivo, texto);
    for(int k = 0 ; k < 100; k++) {
        int num = std::stoi(texto);
        tree.insert(num);
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
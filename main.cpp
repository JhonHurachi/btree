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

    BTree tree(128);
    createFile();
    string texto;
    ifstream archivo;
    archivo.open("archivoTerminado.txt", ios::in);

    getline(archivo, texto);
    while (!archivo.eof())
    {
        int num = std::stoi(texto);
        tree.insert(num);
        getline(archivo, texto);
    }

    if (tree.search(6) != nullptr)

        cout << "\nPresente";

    else

        cout << "\nAusente";

    cout << endl;

    tree.remove(6);

    cout << "El árbol organizado horizontalmente es: \n";

    tree.traverse();

    cout << endl;

    cin.get();
    return 0;
}
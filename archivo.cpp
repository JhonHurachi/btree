
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    const string fichero3="archivoTerminado.txt";
    ofstream archivo;
    archivo.open(fichero3.c_str());

    for(int k = 0 ; k < 100; k++) {

        archivo << rand() % 100 + 1 << endl;
    }
 
    archivo.close();
 
}

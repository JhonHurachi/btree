
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;
int main()
{
    const string fichero3 = "archivoTerminado.txt";
    ofstream archivo;
    archivo.open(fichero3.c_str());

    for (int k = 0; k < 1000; k++)
    {
        archivo << rand() % 1000 + 1 << endl;
    }

    archivo.close();
}

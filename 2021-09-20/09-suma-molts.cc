// programa que suma una seqüència d'enters

// recordeu que quan es llegeix del tecat, cal assenyalar el final
// de l'entrada amb Control+D

#include <iostream>
using namespace std;

int main()
{
    int suma = 0;
    int x;
    while (cin >> x) { // "mentre puguis llegir un enter, desa'l en x"
        suma = suma + x;
    }
    cout << suma << endl;
}

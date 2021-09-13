// programa que llegeix dos nombres
// i escriu el seu màxim

#include <iostream>
using namespace std;

int main()
{
    // llegir entrades
    int a, b;
    cin >> a >> b;
    // calcular resultat
    int m;
    if (a >= b) {
        m = a;
    } else {
        m = b;
    }
    // escriure resultat
    cout << m << endl;
}

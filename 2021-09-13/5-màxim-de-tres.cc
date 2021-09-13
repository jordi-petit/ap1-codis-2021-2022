// programa que llegeix tres nombres
// i escriu el seu màxim

#include <iostream>
using namespace std;

int main()
{
    // llegir entrades
    int a, b, c;
    cin >> a >> b >> c;
    // calcular resultat
    int m;
    if (a >= b and a >= c) {
        m = a;
    } else if (b >= a and b >= c) {
        m = b;
    } else {
        m = c;
    }
    // escriure sortida
    cout << m << endl;
}

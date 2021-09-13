// programa que llegeix tres nombres
// i escriu el seu màxim

// versió amb condicionals aniuats

#include <iostream>
using namespace std;

int main()
{
    // llegir entrada
    int a, b, c;
    cin >> a >> b >> c;
    // calcular resultat
    int m;
    if (a > b) {
        if (a > c) {
            m = a;
        } else {
            m = c;
        }
    } else {
        if (b > c) {
            m = b;
        } else {
            m = c;
        }
    }
    // escriure resultat
    cout << m << endl;
}

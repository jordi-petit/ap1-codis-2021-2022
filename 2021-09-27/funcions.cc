#include <iostream>
using namespace std;

// La funció minim calcula el valor més petit
// de dos enters donats.
int minim(int x, int y)
{
    if (x <= y) {
        return x;
    } else {
        return y;
    }
}

// Funció que retorna el màxim de tres enters.
int minim3(int x, int y, int z)
{
    return minim(x, minim(y, z));
}

// Retorna el valor valor absolut d'un enter.
int valor_absolut(int x)
{
    if (x >= 0) {
        return x;
    } else {
        return -x;
    }
}

// Retorna el factorial d'un enter n donat.
// Precondició: n >= 0.
int factorial(int n)
{
    int f = 1;
    for (int i = 2; i <= n; ++i) {
        f *= i;
    }
    return f;
}

// Diu si un nombre és primer o no.
// Precondició: Cal que el nombre sigui positiu o zero.
bool es_primer(int n)
{
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// Retorna el màxim comú divisor de dos enters a i b
// tals que a >=0 i b >= 0 però no a = b = 0.
int mcd(int a, int b)
{
    // alg d'Euclides (lent)
    while (a != b) {
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    }
    return a;
}

int main()
{
    /*
    int x;
    cin >> x;
    for (int n = 0; n <= x; ++n) {
        if (es_primer(n)) {
            cout << n << endl;
        }
    }
    */

    int a, b;
    cin >> a >> b;
    cout << mcd(a, b) << endl;
}

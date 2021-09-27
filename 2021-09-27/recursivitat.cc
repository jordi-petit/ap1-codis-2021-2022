#include <iostream>
using namespace std;

// Retorna el factorial d'un enter n donat.
// Precondició: n >= 0.
int factorial(int n)
{
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

// retorna x ^ y amb y >= 0
int eleva(int x, int y)
{
    if (y == 0) {
        return 1;
    } else {
        return x * eleva(x, y - 1);
    }
}

// retorna x ^ y amb y >= 0
int eleva2(int x, int y)
{
    // exponenciació ràpida
    if (y == 0) {
        return 1;
    } else {
        int z = eleva2(x, y / 2);
        if (y % 2 == 0) {
            return z * z;
        } else {
            return z * z * x;
        }
    }
}

// Retorna el màxim comú divisor de dos enters a i b
// tals que a >=0 i b >= 0 però no a = b = 0.
int mcd(int a, int b)
{
    // alg d'Euclides (lent)
    if (a == b) {
        return a;
    } else {
        if (a > b) {
            return mcd(a - b, b);
        } else {
            return mcd(a, b - a);
        }
    }
}

// exercici: busqueu com fer el mcd amb alg d'Euclides ràpid
// (idea: substituir moltes restes per un residu)

int main()
{
    for (int i = 0; i < 20; ++i) {
        cout << i << " " << factorial(i) << endl;
    }
    /*
    int a, b;
    cin >> a >> b;
    cout << mcd(a, b) << endl;
    */
}

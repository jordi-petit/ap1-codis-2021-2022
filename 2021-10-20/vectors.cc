// algunes funcions i accions amb vectors

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// retorna el producte escalar de dos vectors
// precondició: els vectors de la mateixa mida
double producte_escalar(vector<double> x, vector<double> y)
{
    double suma = 0;
    int n = x.size();
    for (int i = 0; i < n; ++i) {
        suma = suma + x[i] * y[i];
    }
    return suma;
}

// retorna el mòdul d'un vector
double modul(vector<double> x)
{
    return sqrt(producte_escalar(x, x));
}

int main()
{
    vector<double> v1 = { 1.1, 2.2, 3.3 };
    vector<double> v2 = { 0, 4.2, -2.1 };
    cout << producte_escalar(v1, v2) << endl;
    cout << modul(v1) << endl;
}

// algunes funcions i accions amb vectors

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// exemple de declaracions de constants
const double pi = 3.14;
const double dolars = 0.81;
const string missatge_benvinguda = "Welcome!";

// retorna el producte escalar de dos vectors
// precondició: els vectors de la mateixa mida
double producte_escalar(const vector<double>& x, const vector<double>& y)
{
    double suma = 0;
    const int n = x.size();
    for (int i = 0; i < n; ++i) {
        suma = suma + x[i] * y[i];
    }
    return suma;
}

// retorna el mòdul d'un vector
double modul(const vector<double>& x)
{
    return sqrt(producte_escalar(x, x));
}

// retorna el mínim d'un vector
// prec: el vector no és buit
double minim(const vector<double>& v)
{
    double m = v[0];
    for (int i = 1; i < v.size(); ++i) {
        if (v[i] < m) {
            m = v[i];
        }
    }
    return m;
}

// retorna el mínim d'un vector
// prec: el vector no és buit
double minim2(const vector<double>& v)
{
    double m = v[0];
    for (double x : v) { // per a cada element x del vector
        if (x < m) {
            m = x;
        }
    }
    return m;
}

// multiplica cada posició del vector v per c.
void escalar(vector<double>& v, double c)
{
    for (double& x : v) { // ep! amb &
        x = x * c;
    }
}

// retorna un (nou) vector resultant de multiplicar cada posició de v per c.
vector<double> escala(vector<double> v, double c)
{
    escalar(v, c);
    return v;
}

// diu si x està inclòs en v o no
bool conte(const vector<double>& v, double x)
{
    for (double y : v) {
        if (y == x) {
            return true;
        }
    }
    return false;
}

// escriu el vecor v de forma "maca".
void escriure(const vector<double>& v)
{
    cout << '{';
    bool primera = true; // diu si és o no la primera iteració del bucle (per separar amb comes els elements)
    for (double x : v) {
        if (primera) {
            primera = false;
        } else {
            cout << ',';
        }
        cout << x;
    }
    cout << '}' << endl;
}

// algunes proves
int main()
{
    vector<double> v1 = { 1.1, 2.2, 3.3 };
    vector<double> v2 = { 0, 4.2, -2.1 };
    cout << producte_escalar(v1, v2) << endl;
    cout << modul(v1) << endl;

    vector<double> v = { 3, 2, 1 };
    escalar(v, 2);
    escriure(v);
}

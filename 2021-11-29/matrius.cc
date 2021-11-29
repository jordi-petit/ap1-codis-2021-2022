#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

using Fila = vector<int>;
using Matriu = vector<Fila>;

void escriure(const Matriu& m)
{
    int n = m.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << m[i][j] << ' ';
        }
        cout << endl;
    }
}

// transposa la matriu m.
// prec: m és quadrada
void transposar(Matriu& m)
{
    int n = m.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            swap(m[i][j], m[j][i]);
        }
    }
}

// indica si m és matriu
// prec: m és quadrada
bool es_simetrica(const Matriu& m)
{
    int n = m.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (m[i][j] != m[j][i]) {
                return false;
            }
        }
    }
    return true;
}

// retorna el producte matricial de a i de b
// prec: a i b són quadrades i de la mateixa mida
Matriu producte(const Matriu& a, const Matriu& b)
{
    int n = a.size();
    Matriu c(n, Fila(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return c;
}

int main()
{
    Matriu m = {
        { 1, 5, 7 },
        { 8, 3, 2 },
        { 9, 3, 8 },
    };

    // cout << es_simetrica(m) << endl;
    // transposar(m);

    m = producte(m, m);

    escriure(m);
}

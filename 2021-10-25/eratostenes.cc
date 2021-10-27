// algorisme d'Erastotenes per a trobar tots els primers fins a un nombre donat.
#include <iostream>
#include <vector>
using namespace std;

// retorna un vector g de n+1 booleans tal que
// g[i] indica si i és o no és primer.
// Prec: n >= 2.
vector<bool> eratostenes(int n)
{
    vector<bool> g(n + 1, true);
    g[0] = false;
    g[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (g[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                g[j] = false;
            }
        }
    }
    return g;
}

// retorna un vector amb tots els nombres primers <= n.
// Prec: n >= 2
vector<int> primers(int n)
{
    vector<int> ps;
    vector<bool> g = eratostenes(n);
    for (int i = 2; i <= n; ++i) {
        if (g[i]) {
            ps.push_back(i);
        }
    }
    return ps;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ps = primers(n);
    for (int p : ps) {
        cout << p << endl;
    }
}

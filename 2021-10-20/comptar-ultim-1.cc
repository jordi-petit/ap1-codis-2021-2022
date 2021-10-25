// llegir 10 enters i escriure quants són iguals al darrer

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 10;
    vector<int> v(n);

    // llegir les dades i desar-les al vector
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }

    // comptar quants elements del vector son iguals a l'ultim
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == v[n - 1]) {
            ++c;
        }
    }
    cout << c << endl;
}

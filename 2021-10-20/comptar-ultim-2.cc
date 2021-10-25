// llegir una seqüència de reals i escriure quants són iguals al darrer

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;

    // llegir les dades i desar-les al vector
    int x;
    while (cin >> x) {
        v.push_back(x);
    }

    // comptar quants elements del vector son iguals a l'ultim
    int n = v.size();
    int c = 0;
    for (int i = 0; i < n; ++i) {
        if (v[i] == v[n - 1]) {
            ++c;
        }
    }
    cout << c << endl;
}

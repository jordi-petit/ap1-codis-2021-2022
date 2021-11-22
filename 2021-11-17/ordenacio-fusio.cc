#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// escriu els elements d'un vector
void escriure(const vector<int>& v)
{
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

// fusiona els elements de v[esq..dre] sabent que
// v[esq..mig] està ordenat i v[mig+1..dre] està ordenat
void merge(vector<int>& v, int esq, int mig, int dre)
{
    vector<int> f(dre - esq + 1);
    int i = esq;
    int j = mig + 1;
    int k = 0;
    while (i <= mig and j <= dre) {
        if (v[i] <= v[j]) {
            f[k++] = v[i++];
        } else {
            f[k++] = v[j++];
        }
    }
    while (i <= mig) {
        f[k++] = v[i++];
    }
    while (j <= dre) {
        f[k++] = v[j++];
    }
    for (k = 0; k < dre - esq + 1; ++k) {
        v[esq + k] = f[k];
    }
}

// ordena v[esq..dre]
void mergesort_rec(vector<int>& v, int esq, int dre)
{
    if (esq < dre) {
        int mig = (esq + dre) / 2;
        mergesort_rec(v, esq, mig);
        mergesort_rec(v, mig + 1, dre);
        merge(v, esq, mig, dre);
    }
}

// ordena v
void mergesort(vector<int>& v)
{
    mergesort_rec(v, 0, v.size() - 1);
}

int main()
{
    vector<int> v = { 5, 7, 2, 3, 4, 5, 2, 9 };
    mergesort(v);
    escriure(v);
}

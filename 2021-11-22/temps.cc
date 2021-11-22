#include <algorithm>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

// retorna el nombre de segons des d'algun punt fix en el temps
double now()
{
    return clock() / double(CLOCKS_PER_SEC);
}

// crea un vector amb n elements a l'atzar
vector<int> crea(int n)
{
    vector<int> v(n);
    for (int& x : v) {
        x = rand() % n;
    }
    return v;
}

// indica si el vector v està ordenat
bool ordenat(const vector<int>& v)
{
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        if (v[i - 1] > v[i]) {
            return false;
        }
    }
    return true;
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

// ordena v amb l'algorisme d'ordenació per fusió
void mergesort(vector<int>& v)
{
    mergesort_rec(v, 0, v.size() - 1);
}

// retorna la posició de l'element mínim en v[i..].
int pos_min(const vector<int>& v, int i)
{
    int n = v.size();
    int p = i;
    for (int j = i + 1; j < n; ++j) {
        if (v[j] < v[p]) {
            p = j;
        }
    }
    return p;
}

// ordena v amb l'algorisme d'ordenació per selecció
void selsort(vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        int p = pos_min(v, i);
        swap(v[i], v[p]);
    }
}

int main()
{
    for (int n = 0; n <= 10000000; n += 1000000) {
        vector<int> v = crea(n);
        double t1 = now();
        mergesort(v);
        double t2 = now();
        cout << n << "\t" << t2 - t1 << endl;
        assert(ordenat(v));
    }
}

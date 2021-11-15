#include <iostream>
#include <vector>
using namespace std;

int posicio_ite(const vector<int>& v, int x)
{
    int esq = 0;
    int dre = v.size() - 1;
    while (esq <= dre) {
        int mig = (esq + dre) / 2;
        if (x < v[mig])
            esq = mig + 1;
        else if (x > v[mig])
            dre = mig - 1;
        else
            return mig;
    }
    return -1;
}

int posicio_rec(const vector<int>& v, int x, int esq, int dre)
{
    if (esq > dre) {
        return -1;
    } else {
        int mig = (dre + esq) / 2;
        if (x < v[mig])
            return posicio_rec(v, x, esq, mig - 1);
        else if (x > v[mig] > x)
            return posicio_rec(v, x, mig + 1, dre);
        else
            return mig;
    }
}

// retorna una posició de v on es troba x
// o bé -1 si x no es troba en v
// prec: el vector v està ordenat creixentment
int posicio_en_vector_ordenat(const vector<int>& v, int x)
{
    return posicio_rec(v, x, 0, v.size() - 1);
}

int main()
{
    vector<int> v = { 2, 2, 3, 4, 5, 5, 7, 9 };
    cout << posicio_en_vector_ordenat(v, 2) << endl;
}

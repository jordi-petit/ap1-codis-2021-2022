#include <iostream>
#include <vector>
using namespace std;

// retorna una posició de v on es troba x
// o bé -1 si x no es troba en v
int posicio(const vector<int>& v, int x)
{
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = { 5, 7, 2, 3, 4, 5, 2, 9 };
    cout << posicio(v, 2) << endl;
}

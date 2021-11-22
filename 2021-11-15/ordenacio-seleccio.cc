#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void write(const vector<int>& v)
{
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int posicio_minim(const vector<int>& v, int i)
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

void selsort(vector<int>& v)
{
    int n = v.size();
    for (int i = 0; i < n - 1; ++i) {
        int p = posicio_minim(v, i);
        swap(v[i], v[p]);
    }
}

int main()
{
    vector<int> v = { 5, 7, 2, 3, 4, 5, 2, 9 };
    selsort(v);
    write(v);
}

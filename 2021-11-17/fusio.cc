#include <iostream>
#include <vector>
using namespace std;

void escriure(const vector<int>& v)
{
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

// retorna una vector ordenat amb la unió dels elements de v1 i de v2
// precondició: v1 i v2 estan ordenats
vector<int> fusio(const vector<int>& v1, const vector<int>& v2)
{
    vector<int> v;
    int n1 = v1.size();
    int n2 = v2.size();
    int i1 = 0;
    int i2 = 0;
    while (i1 < n1 and i2 < n2) {
        if (v1[i1] < v2[i2]) {
            v.push_back(v1[i1]);
            ++i1;
        } else {
            v.push_back(v2[i2]);
            ++i2;
        }
    }
    while (i1 < n1) {
        v.push_back(v1[i1]);
        ++i1;
    }
    while (i2 < n2) {
        v.push_back(v2[i2]);
        ++i2;
    }
    return v;
}

int main()
{
    vector<int> v1 = { 2, 5, 8, 13, 21, 23, 28 };
    vector<int> v2 = { 3, 3, 5, 7, 15 };
    vector<int> v = fusio(v1, v2);
    escriure(v);
}

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

void inssort(vector<int>& v)
{
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        int j = i;
        while (j > 0 and v[j - 1] > v[j]) {
            swap(v[j - 1], v[j]);
            --j;
        }
    }
}

void inssort2(vector<int>& v)
{
    int n = v.size();
    for (int i = 1; i < n; ++i) {
        int j = i;
        int x = v[j];
        while (j > 0 and v[j - 1] > x) {
            v[j] = v[j - 1];
            --j;
        }
        v[j] = x;
    }
}

int main()
{
    vector<int> v = { 5, 7, 2, 3, 4, 5, 2, 9 };
    inssort2(v);
    write(v);
}

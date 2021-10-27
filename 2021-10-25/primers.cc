#include <iostream>
#include <vector>
using namespace std;

// indica si un natural n és o no primer
bool es_primer(int n)
{
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

// programa que compta tots els nombres primers fins a n
int main()
{
    int n;
    cin >> n;
    int c = 0;
    for (int i = 2; i <= n; ++i) {
        if (es_primer(i)) {
            ++c;
        }
    }
    cout << c << endl;
}

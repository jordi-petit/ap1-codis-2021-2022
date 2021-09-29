
// programa que calcula la mitjana d'una
// seqüència de reals

#include <iostream>
using namespace std;

int main()
{
    double s = 0;
    int n = 0;
    double x;
    while (cin >> x) {
        s = s + x;
        n = n + 1;
    }
    cout << s / n << endl;
}

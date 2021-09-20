// programa per determinar si un nombre n >= 2 és primer o no
// primera versió

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int compost = 0;
    int d = 2;
    while (d <= n - 1) {
        if (n % d == 0) {
            compost = 1;
        }
        d = d + 1;
    }

    if (compost == 0) {
        cout << n << " és primer" << endl;
    } else {
        cout << n << " no és primer" << endl;
    }
}

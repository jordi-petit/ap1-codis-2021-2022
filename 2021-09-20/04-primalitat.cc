// programa per determinar si un nombre n >= 0 és primer o no
// amb control per 0 i 1

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool compost = n <= 1;
    int d = 2;
    while (d <= n - 1 and not compost) {
        if (n % d == 0) {
            compost = true;
        }
        d = d + 1;
    }

    if (not compost) {
        cout << n << " és primer" << endl;
    } else {
        cout << n << " no és primer" << endl;
    }
}

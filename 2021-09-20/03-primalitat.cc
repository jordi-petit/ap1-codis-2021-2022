// programa per determinar si un nombre n >= 2 és primer o no
// amb sortida del bucle quan és compost

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool compost = false;
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

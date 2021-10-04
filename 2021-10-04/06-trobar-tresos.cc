#include <iostream>
using namespace std;

// donat un natural n, diu n en decimal conté algun 3
bool hi_ha_tresos(int n)
{
    while (n > 0) {
        if (n % 10 == 3) {
            return true;
        }
        n = n / 10;
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    cout << hi_ha_tresos(n) << endl;
}

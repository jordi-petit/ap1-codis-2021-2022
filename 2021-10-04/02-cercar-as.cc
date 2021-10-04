// programa que diu si hi ha alguna 'a' a l'entrada: cerca

#include <iostream>
using namespace std;

int main()
{
    bool hi_ha_as = false;
    char c;
    while (cin >> c and not hi_ha_as) {
        if (c == 'a') {
            hi_ha_as = true;
        }
    }
    if (hi_ha_as) {
        cout << "sí" << endl;
    } else {
        cout << "no" << endl;
    }
}

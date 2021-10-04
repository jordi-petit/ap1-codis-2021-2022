#include <iostream>
using namespace std;

// incrementa d'un segon l'hora del rellotge.
void incrementar_un_segon(int& h, int& m, int& s)
{
    ++s;
    if (s == 60) {
        s = 0;
        ++m;
        if (m == 60) {
            m = 0;
            ++h;
            if (h == 24) {
                h = 0;
            }
        }
    }
}

int main()
{
    int h, m, s;
    cin >> h >> m >> s;
    incrementar_un_segon(h, m, s);
    cout << h << ' ' << m << ' ' << s << endl;
}

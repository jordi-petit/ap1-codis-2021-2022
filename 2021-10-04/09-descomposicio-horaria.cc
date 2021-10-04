#include <iostream>
using namespace std;

// donat un nombre de segons n, retorna el temps equivalent en hores (h),
// minuts (m) i segons (s).
void descomposicio_horaria(int n, int& h, int& m, int& s)
{
    h = n / 3600;
    m = (n % 3600) / 60;
    s = (n % 3600) % 60;
}

int main()
{
    int n;
    cin >> n;
    int hores, m, s;
    descomposicio_horaria(n, hores, m, s);
    cout << hores << ":" << m << ":" << s << endl;
}

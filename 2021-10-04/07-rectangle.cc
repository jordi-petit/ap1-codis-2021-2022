// programa que escriu un rectangle mitjançant accions

#include <iostream>
using namespace std;

void escriure_linia(int n, char c = '*')
{
    for (int i = 0; i < n; ++i) {
        cout << c;
    }
    cout << endl;
}

void escriure_quadrat(int n, char c = '*')
{
    for (int i = 0; i < n; ++i) {
        escriure_linia(n, c);
    }
}

int main()
{
    int n;
    cin >> n;
    escriure_quadrat(n, 'o');
    escriure_quadrat(n);
}

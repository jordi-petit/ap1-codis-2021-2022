#include <iostream>
using namespace std;

// donat un natural n, retorna el nombre de dígits 3 que conté n en decimal
int nombre_de_tresos(int n)
{
    int tresos = 0;
    while (n > 0) {
        if (n % 10 == 3) {
            ++tresos;
        }
        n = n / 10;
    }
    return tresos;
}

int main()
{
    int n;
    cin >> n;
    cout << nombre_de_tresos(n) << endl;
}

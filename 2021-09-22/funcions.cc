// alguns exemples de funcions, acabeu d'implementar
// i de provar les dues darreres

#include <iostream>
using namespace std;

int minim(int x, int y)
{
    int m;
    if (x <= y) {
        m = x;
    } else {
        m = y;
    }
    return m;
}

int minim3(int x, int y, int z)
{
    int m = minim(x, minim(y, z));
    return m;
}

int valor_absolut(int x)
{
}

int factorial(int n)
{
}

int main()
{
    int x, z, y;
    cin >> x >> z >> y;
    cout << minim3(x, z, y) << endl;
}

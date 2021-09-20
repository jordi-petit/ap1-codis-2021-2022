// programa que escriu una taula de multiplicar

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int i = 0;
    while (i <= 10) {
        cout << i << " * " << n << " = " << i * n << endl;
        i = i + 1;
    }
}

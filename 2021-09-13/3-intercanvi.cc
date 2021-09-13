// programa que intercanvia el valor de dues variables

#include <iostream>
using namespace std;

int main()
{
    int a = 4;
    int b = 2;

    int c = a;
    a = b;
    b = c;

    cout << a << endl
         << b << endl;
}

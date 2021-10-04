#include <iostream>
using namespace std;

// intercanvia els valors de x i y
void swap(int& x, int& y)
{
    int z = x;
    x = y;
    y = z;
}

int main()
{
    int a = 2;
    int b = 3;

    cout << a << endl
         << b << endl;

    swap(a, b);

    cout << a << endl
         << b << endl;
}

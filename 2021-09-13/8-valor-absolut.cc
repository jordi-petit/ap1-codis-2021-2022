// programa que llegeix un nombre i escriu
// el seu valor absolut

#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    if (a < 0) {
        a = -a;
    }
    cout << a << endl;
}

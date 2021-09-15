// programa que llegeix un natural i n'escriu el seu factorial

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int f = 1;
    int i = 1; // també funciona amb 2
    while (i <= n) {
        f = f * i;
        i = i + 1;
    }

    cout << f << endl;
}

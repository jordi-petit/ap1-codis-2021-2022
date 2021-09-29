// programa que llegeix una lletra minúscula i l'escriu en majúscula

#include <iostream>
#include <string>
using namespace std;

int main()
{
    char c;
    cin >> c;
    c = c - 'a' + 'A';
    cout << c << endl;
}

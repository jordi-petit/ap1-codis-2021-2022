// programa que escriu les taules de multiplicar

#include <iostream>
using namespace std;

int main()
{
    int j = 0;
    while (j <= 10) {
        int i = 0;
        while (i <= 10) {
            cout << i << " * " << j << " = " << i * j << endl;
            i = i + 1;
        }
        cout << endl;
        j = j + 1;
    }
}

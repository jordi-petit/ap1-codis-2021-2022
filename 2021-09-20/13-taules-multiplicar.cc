// programa que escriu les taules de multiplicar

#include <iostream>
using namespace std;

int main()
{
    for (int j = 0; j <= 10; ++j) {
        for (int i = 0; i <= 10; ++i) {
            cout << i << " * " << j << " = " << i * j << endl;
        }
        cout << endl;
    }
}

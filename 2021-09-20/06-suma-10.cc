// programa que suma 10 enters

#include <iostream>
using namespace std;

int main()
{
    int suma = 0;
    int i = 1;
    while (i <= 10) {
        int x;
        cin >> x;
        suma = suma + x;
        i = i + 1;
    }
    cout << suma << endl;
}

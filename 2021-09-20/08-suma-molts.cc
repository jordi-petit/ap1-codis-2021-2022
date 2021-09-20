// programa que suma una seqüència de naturals, acabada per un negatiu

#include <iostream>
using namespace std;

int main()
{
    int suma = 0;
    int x;
    cin >> x;
    while (x >= 0) {
        suma = suma + x;
        cin >> x;
    }
    cout << suma << endl;
}

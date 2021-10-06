// programa per resoldre el problema de les torres de Hanoi.

#include <iostream>
using namespace std;

// escriu com moure n discos del piu aux
// al piu dst utilitzant el piu aux.
void hanoi(int n, char ori, char aux, char dst)
{
    if (n > 0) {
        hanoi(n - 1, ori, dst, aux);
        cout << ori << " -> " << dst << endl;
        hanoi(n - 1, aux, ori, dst);
    }
}

int main()
{
    int n;
    cin >> n;
    hanoi(n, 'a', 'b', 'c');
}

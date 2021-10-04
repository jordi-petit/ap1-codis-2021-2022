// programa que compta el nombre de 'a's a l'entrada: recorregut

#include <iostream>
using namespace std;

int main()
{
    int nb_as = 0;
    char c;
    while (cin >> c) {
        if (c == 'a') {
            ++nb_as;
        }
    }
    cout << nb_as << endl;
}

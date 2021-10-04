// programa que compta el nombre de 'la's a l'entrada: recorregut amb finestra de 2

#include <iostream>
using namespace std;

int main()
{
    int nb_las = 0;
    char c1, c2;
    cin >> c1;
    while (cin >> c2) {
        if (c1 == 'l' and c2 == 'a') {
            ++nb_las;
        }
        c1 = c2;
    }
    cout << nb_las << endl;
}

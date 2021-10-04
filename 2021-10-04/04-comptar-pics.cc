// programa que compta el nombre de pics en una seqüència d'enters

#include <iostream>
using namespace std;

// indica si (a,b,c) forma un pic
bool es_pic(int a, int b, int c)
{
    return b > a and b > c;
}

int main()
{
    int nb_pics = 0;
    int x1, x2, x3;
    cin >> x1 >> x2;
    while (cin >> x3) {
        if (es_pic(x1, x2, x3)) {
            ++nb_pics;
        }
        x1 = x2;
        x2 = x3;
    }
    cout << nb_pics << endl;
}

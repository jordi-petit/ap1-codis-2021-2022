#include <iostream>
using namespace std;

// Dibuixa la parabola a*x^2 + b*x + c en l'interval [0,d]
void parabola(int a, int b, int c, int d)
{
    for (int x = 0; x <= d; ++x) {
        int y = a * x * x + b * x + c;
        for (int i = 0; i < y; ++i) {
            cout << 'X';
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

// Programa principal que llegeix els valors a, b, c i d
// i dibuixa la parabola segons l'enunciat
int main()
{
    int a, b, c, d;
    while (cin >> a >> b >> c >> d) {
        parabola(a, b, c, d);
    }
}

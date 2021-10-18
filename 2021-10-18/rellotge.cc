#include <iostream>
using namespace std;

void traduir_valor()
{
    char c;
    int x = 0;
    cin >> c;
    while (c != '|') {
        if (c == '$') {
            x = x * 2;
        } else {
            x = x * 2 + 1;
        }
        cin >> c;
    }
    cout << x;
}

void traduir_hora()
{
    char barra;
    cin >> barra;
    traduir_valor();
    cout << ":";
    traduir_valor();
    cout << ":";
    traduir_valor();
    cout << endl;
}

int main()
{
    int casos;
    cin >> casos;
    for (int i = 0; i < casos; ++i) {
        traduir_hora();
    }
}

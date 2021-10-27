#include <iostream>
#include <vector>
using namespace std;

// diu si text conté patro a la posició p
bool encaixa(string text, string patro, int p)
{
    for (int i = 0; i < patro.size(); ++i) {
        if (patro[i] != text[p + i]) {
            return false;
        }
    }
    return true;
}

// diu si text conté patro
bool conte(string text, string patro)
{
    int n = text.size();
    int m = patro.size();
    for (int p = 0; p < n - m; ++p) {
        if (encaixa(text, patro, p)) {
            return true;
        }
    }
    return false;
}

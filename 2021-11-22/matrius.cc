#include <iostream>
#include <vector>
using namespace std;

using Fila = vector<int>;
using Matriu = vector<Fila>;

void escriure(const Matriu& M)
{
    int m = M.size();
    int n = M[0].size();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

// O(m·n)
// prec: A  i b són de la mateixa mida, A tingui alguna fila
Matriu suma(const Matriu& A, const Matriu B)
{
    int m = A.size();
    int n = A[0].size();
    Matriu C = A;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] += B[i][j];
        }
    }
    return C;
}

int main()
{
    Matriu M1 = {
        { 1, 2, 3 },
        { 4, 5, 6 },
        { 7, 8, 9 },
        { 11, 12, 13 },
    };
    Matriu M2 = M1;
    Matriu M3 = suma(M1, M2);
    escriure(M3);
}

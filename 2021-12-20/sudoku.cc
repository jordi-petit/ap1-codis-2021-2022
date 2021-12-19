#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Conjunt de valors de 0 a 8 com a vector de booleans.
using Conjunt = vector<bool>;

// Un Sudoku correspon a una matriu 9x9 de Conjunts.
using Sudoku = vector<vector<Conjunt>>;

// Algunes constants
Conjunt conjunt_ple = Conjunt(9, true);
Conjunt conjunt_buit = Conjunt(9, false);

// Crea un conjunt amb un sol element e.
Conjunt conjunt_unitari(int e)
{
    Conjunt c = conjunt_buit;
    c[e] = true;
    return c;
}

// Retorna el nombre d'elements en un conjunt.
int mida(const Conjunt& c)
{
    int n = 0;
    for (int i = 0; i < 9; ++i) {
        if (c[i]) {
            ++n;
        }
    }
    return n;
}

// Retorna l'únic element d'un conjunt que només té un element.
// Prec: el conjunt té mida 1.
int unic(const Conjunt& c)
{
    assert(mida(c) == 1);
    for (int i = 0; i < 9; ++i) {
        if (c[i]) {
            return i;
        }
    }
    assert(false);
}

// Diu si un Sudoku està resolt (tots els seus conjunts tenen un sol element).
bool resolt(const Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (mida(s[i][j]) != 1) {
                return false;
            }
        }
    }
    return true;
}

// Diu si un Sudoku ha fallat (algun dels seus conjunts és buit).
bool fallat(const Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (mida(s[i][j]) == 0) {
                return true;
            }
        }
    }
    return false;
}

// Retorna el sudoku llegit de l'entrada.
Sudoku llegir()
{
    Sudoku s(9, vector<Conjunt>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            char c;
            cin >> c;
            if (c != '.') {
                s[i][j] = conjunt_unitari(c - '1');
            } else {
                s[i][j] = conjunt_ple;
            }
        }
    }
    return s;
}

// Escriu un sudoku tal com cal.
// Prec: el sudoku està solucionat.
void escriure(const Sudoku& s)
{
    assert(resolt(s));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << unic(s[i][j]) + 1 << " ";
        }
        cout << endl;
    }
}

// Escriu un sudoku amb els seus conjunts (per treballar).
void xivar(const Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << "[";
            for (int k = 0; k < 9; ++k) {
                if (s[i][j][k]) {
                    cout << k;
                } else {
                    cout << " ";
                }
            }
            cout << "] ";
        }
        cout << endl;
    }
    cout << endl;
}

void propogar_restriccions_casella_a_fila(Sudoku& s, int i, int j, int e)
{
    for (int jj = 0; jj < 9; ++jj) {
        if (jj != j) {
            s[i][jj][e] = false;
        }
    }
}

void propogar_restriccions_casella_a_columna(Sudoku& s, int i, int j, int e)
{
    for (int ii = 0; ii < 9; ++ii) {
        if (ii != i) {
            s[ii][j][e] = false;
        }
    }
}

void propogar_restriccions_casella_a_caixa(Sudoku& s, int i, int j, int e)
{
    int ci = (i / 3) * 3;
    int cj = (j / 3) * 3;
    for (int ii = 0; ii < 3; ++ii) {
        for (int jj = 0; jj < 3; ++jj) {
            if (ci + ii != i or cj + jj != j) {
                s[ci + ii][cj + jj][e] = false;
            }
        }
    }
}

// Propaga les restriccions de la casella i,j.
// Prec: la mida del conjunt de la casella i,j és 1.
void propogar_restriccions_casella(Sudoku& s, int i, int j)
{
    int e = unic(s[i][j]);
    propogar_restriccions_casella_a_fila(s, i, j, e);
    propogar_restriccions_casella_a_columna(s, i, j, e);
    propogar_restriccions_casella_a_caixa(s, i, j, e);
}

// Propaga les restriccions de totes les caselles.
void propagar_restriccions_arreu(Sudoku& s)
{
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (mida(s[i][j]) == 1) {
                propogar_restriccions_casella(s, i, j);
            }
        }
    }
}

// Propaga les restriccions del sudoku tant com es pugui.
void propagar_restriccions(Sudoku& s)
{
    Sudoku s2;
    while (s != s2) { // a la primera iteració segur que entra, perquè s2 és buit i s no.
        s2 = s;
        propagar_restriccions_arreu(s);
    }
}

// Tria quina cel·la usar per fixar el seu valor (mínim de candidats)
void triar_cella(const Sudoku& s, int& i, int& j)
{
    int m = 10;
    for (int ii = 0; ii < 9; ++ii) {
        for (int jj = 0; jj < 9; ++jj) {
            int c = mida(s[ii][jj]);
            if (c > 1 and c < m) {
                m = c;
                i = ii;
                j = jj;
            }
        }
    }
}

// Prova de resoldre el sudoku amb propagació de restriccions.
void provar_de_resoldre_1(Sudoku& s)
{
    propagar_restriccions(s);
}

// Prova de resoldre el sudoku amb cerca exhaustiva.
void provar_de_resoldre_2(Sudoku& s)
{
    propagar_restriccions(s);
    if (not resolt(s) and not fallat(s)) {
        int i, j;
        triar_cella(s, i, j);
        Sudoku s2 = s;
        for (int k = 0; k < 9; ++k) {
            if (s[i][j][k]) {
                s[i][j] = conjunt_unitari(k);
                provar_de_resoldre_2(s);
                if (resolt(s)) {
                    return;
                }
                s = s2;
            }
        }
    }
}

// Llegeix un sudoku i prova de resoldre'l, tot escrivint el resultat.
int main()
{
    Sudoku s = llegir();
    provar_de_resoldre_1(s);
    if (resolt(s)) {
        escriure(s);
    } else {
        cout << "no s'ha trobat solució" << endl;
    }
}

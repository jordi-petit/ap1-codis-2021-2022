// exemple d'ús de textos

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Quin és el teu nom?" << endl;
    string nom;
    cin >> nom;
    cout << "Quin és el teu cognom?" << endl;
    string cognom;
    cin >> cognom;
    string nom_complet = nom + " " + cognom;
    cout << "Hola " << nom_complet << "!" << endl;
}

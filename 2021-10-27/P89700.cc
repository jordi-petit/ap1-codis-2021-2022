#include <iostream>
using namespace std;

// Llegeix una seqüència d'enters acabada en zero i
// desa en buida si és buida, en suma la suma dels seus elements,
// i en darrer el darrer dels seus elements (si no era buida).
void processar_sequencia(bool& buida, int& suma, int& darrer)
{
    suma = 0;
    int element;
    cin >> element;
    buida = element == 0;
    while (element != 0) {
        suma += element;
        darrer = element;
        cin >> element;
    }
}

int main()
{
    // processar primera seqüència
    bool buida;
    int suma_primera, darrer_primera; // dades de la primera seqüència
    processar_sequencia(buida, suma_primera, darrer_primera);

    // processar seqüencies següents
    int similars = 1; // nombre de seqüències similars (cal comptar la primera)
    int suma, darrer; // dades de la seqüència següent
    processar_sequencia(buida, suma, darrer);
    while (not buida) {
        if (suma == suma_primera and darrer == darrer_primera) {
            ++similars;
        }
        processar_sequencia(buida, suma, darrer);
    }

    // escriure resultat
    cout << similars << endl;
}

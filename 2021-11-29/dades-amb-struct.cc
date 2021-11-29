#include <iostream>
using namespace std;

struct Data {
    int dia;
    int mes;
    int any;
    string nom;
};

struct Hora {
    int hores;
    int minuts;
    int segons;
};

void escriure_data(const Data& data)
{
    cout << data.dia << '-' << data.mes << '-' << data.any << endl;
}

void escriure_hora(const Hora& hora)
{
    cout << hora.hores << ':' << hora.minuts << ':' << hora.segons << endl;
}

void sumar_un_segon(Hora& h)
{
    ++h.segons;
    if (h.segons == 60) {
        h.segons = 0;
        ++h.minuts;
        if (h.minuts == 60) {
            h.minuts = 0;
            ++h.hores;
            if (h.hores == 24) {
                h.hores = 0;
            }
        }
    }
}

int main()
{
    Data avui = { 29, 11, 2021, "dilluns" };
    escriure_data(avui);
    Hora hora = { 11, 5, 31 };
    sumar_un_segon(hora);
    escriure_hora(hora);
}

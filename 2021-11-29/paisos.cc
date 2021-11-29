#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Municipi {
    string nom;
    int poblacio;
    int area;
};

struct Comarca {
    string nom;
    string capital;
    vector<Municipi> municipis;
};

struct Provincia {
    string nom;
    string capital;
    vector<Comarca> comarques;
};

struct Pais {
    string nom;
    string capital;
    string moneda;
    vector<Provincia> provincies;
};

double densitat(const Pais& pais)
{
    int pob = 0;
    int area = 0;

    for (const Provincia& provincia : pais.provincies) {
        for (const Comarca& comarca : provincia.comarques) {
            for (const Municipi& municipi : comarca.municipis) {
                pob += municipi.poblacio;
                area += municipi.area;
            }
        }
    }

    return double(pob) / double(area);
}

int main()
{
    Pais p = {
        "Estats Units",
        "Washinton",
        "Dòlar",
        {
            { "Texas",
                "Dallas",
                { { "Dallas County",
                      "Dallas",
                      {
                          { "Dallas", 3000000, 1000 },
                          { "Dallas de Llobregat", 1000000, 100 },
                      } },
                    { "San Antonio County",
                        "San Antonio",
                        {
                            { "San Antonio", 3000000, 1000 },
                            { "El Paso", 1000000, 100 },
                        } } } },
        }
    };

    cout << densitat(p) << endl;
}

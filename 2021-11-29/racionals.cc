#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Racional {
    int num;
    int den;
};

int maxim_comu_divisor(int a, int b)
{
    if (b == 0)
        return a;
    else
        return maxim_comu_divisor(b, a % b);
}

Racional crear_racional(int numerador, int denominador)
{
    int mcd = maxim_comu_divisor(numerador, denominador);
    return { numerador / mcd, denominador / mcd };
}

void escriure_racional(const Racional& r)
{
    cout << r.num << "/" << r.den << endl;
}

Racional suma(const Racional& r1, const Racional& r2)
{
    return crear_racional(r1.num * r2.den + r2.num * r1.den, r1.den * r2.den);
}

bool menor_estricte(const Racional& r1, const Racional& r2)
{
    ...
}

int main()
{
    Racional r1 = crear_racional(4, 2);
    Racional r2 = crear_racional(5, 4);
    Racional r = suma(r1, r2);
    escriure_racional(r);
}

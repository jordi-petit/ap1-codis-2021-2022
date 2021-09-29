// funcions amb caràcters

#include <iostream>
using namespace std;

bool es_majuscula(char c)
{
    return c >= 'A' and c <= 'Z';
}

bool es_minuscula(char c)
{
    return c >= 'a' and c <= 'z';
}

bool es_lletra(char c)
{
    return es_minuscula(c) or es_majuscula(c);
}

bool es_digit(char c)
{
    return c >= '0' and c <= '9';
}

int digit_a_enter(char c)
{
    return c - '0';
}

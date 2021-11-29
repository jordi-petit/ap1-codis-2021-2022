#include <iostream>
using namespace std;

using Data = vector<int>;

void escriure_data(const Data& data)
{
    cout << data[0] << '-' << data[1] << '-' << data[2] << endl;
}

int main()
{
    Data avui = { 29, 11, 2021 };
    escriure_data(avui);
}

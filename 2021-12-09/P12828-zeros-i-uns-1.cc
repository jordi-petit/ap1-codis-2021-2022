#include <iostream>
#include <vector>

using namespace std;

void pinta_paraula(const vector<int> & paraula, int n)
{
  for (int i = 0; i < n - 1; ++i) {
    cout << paraula[i] << " ";
  }
  cout << paraula[n - 1] << endl;
}

void escriu_paraules_gen(vector<int> & sol_parcial, int i, int n)
{
  if (i == n) pinta_paraula(sol_parcial, n);
  else {
    sol_parcial[i] = 0;
    escriu_paraules_gen(sol_parcial, i + 1, n);
    sol_parcial[i] = 1;
    escriu_paraules_gen(sol_parcial, i + 1, n);
  }
}

void escriu_paraules(int n)
{
  vector<int> sol_parcial(n);
  escriu_paraules_gen(sol_parcial, 0, n);
}

int main()
{
  int n;
  cin >> n;
  escriu_paraules(n);
}

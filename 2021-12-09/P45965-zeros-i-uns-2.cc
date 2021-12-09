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

void escriu_paraules_gen(vector<int> & sol_parcial, int i, int n, int u, int c)
{
  if (i == n) {
    if (c == u) pinta_paraula(sol_parcial, n);
  }
  else {
    if (i - c < n - u) {
      sol_parcial[i] = 0;
      escriu_paraules_gen(sol_parcial, i + 1, n, u, c);
    }
    if (c < u) {
      sol_parcial[i] = 1;
      escriu_paraules_gen(sol_parcial, i + 1, n, u, c + 1);
    }
  }
}

void escriu_paraules(int n, int u)
{
  vector<int> sol_parcial(n);
  escriu_paraules_gen(sol_parcial, 0, n, u, 0);
}

int main()
{
  int n, u;
  cin >> n >> u;
  escriu_paraules(n, u);
}

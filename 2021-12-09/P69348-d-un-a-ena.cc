#include <iostream>
#include <vector>

using namespace std;

void pinta_permut(const vector<int> & permut, int n)
{
  cout << "(";
  for (int i = 0; i < n - 1; ++i) {
    cout << permut[i] << ",";
  }
  cout << permut[n - 1] << ")" << endl;  
}

void escriu_permuts_gen(vector<int> & sol_parcial,
  vector<bool> & ja_hi_es, int i, int n)
{
  if (i == n) pinta_permut(sol_parcial, n);
  else {
    for (int j = 1; j <= n; ++j) {
      if (not ja_hi_es[j]) {
	sol_parcial[i] = j;
	ja_hi_es[j] = true;
	escriu_permuts_gen(sol_parcial, ja_hi_es, i + 1, n);
	ja_hi_es[j] = false;
	sol_parcial[i] = -1;
      }
    }
  }
}

void escriu_permuts(int n)
{
  vector<int> sol_parcial(n, -1);
  vector<bool> ja_hi_es(n + 1, false);
  escriu_permuts_gen(sol_parcial, ja_hi_es, 0, n);
}

int main()
{
  int n;
  cin >> n;
  escriu_permuts(n);
}

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void pinta_particio(const vector<vector<int>> & part,
  const vector<string> & s, int p, int n)
{
  for (int j = 0; j < p; ++j) {
    cout << "subconjunt " << j + 1 << ": ";
    cout << "{";
    int m = part[j].size();
    for (int k = 0; k < m - 1; ++k) {
      cout << s[part[j][k]] << ",";
    }
    if (m > 0) cout << s[part[j][m - 1]];
    cout << "}" << endl;
  }
  cout << endl;
}

void escriu_particions_gen(vector<vector<int>> & sol_parcial,
  int i, const vector<string> & s, int p, int n)
{
  if (i == n) pinta_particio(sol_parcial, s, p, n);
  else {
    for (int j = 0; j < p; ++j) {
      sol_parcial[j].push_back(i);
      escriu_particions_gen(sol_parcial, i + 1, s, p, n);
      sol_parcial[j].pop_back();
    }
  }
}


void escriu_particions(const vector<string> & s, int p, int n)
{
  vector<vector<int>> sol_parcial(p);
  escriu_particions_gen(sol_parcial, 0, s, p, n);
}

int main()
{
  int n;
  cin >> n;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  int p;
  cin >> p;
  escriu_particions(s, p, n);
}


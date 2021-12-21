#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Paraula_i_Freq {
  string paraula;
  int frequencia;
};

/*
void tractar_paraula(vector<Paraula_i_Freq> & v, int & m, string s)
{
  int j = 0;
  while (j < m and v[j].paraula != s) ++j;
  if (j != m) v[j].frequencia++;
  else {
    Paraula_i_Freq a;
    a.paraula = s;
    a.frequencia = 1;
    v.push_back(a);
    ++m;
  }
}
*/

void tractar_paraules(vector<string> & w, vector<Paraula_i_Freq> & v)
{
  sort(w.begin(), w.end());
  int n = w.size();
  if (n == 0) return;
  Paraula_i_Freq a;
  a.paraula = w[0];
  a.frequencia = 1;
  for (int i = 1; i < n; ++i) {
    if (w[i] == a.paraula) a.frequencia++;
    else {
      v.push_back(a);
      a.paraula = w[i];
      a.frequencia = 1;
    }
  }
  v.push_back(a);
}

void escriu_resultat(const vector<Paraula_i_Freq> & v, int k)
{
  for (int i = 0; i < k; ++i) {
    cout << v[i].paraula << endl;
  }
  cout << "----------" << endl;
}

bool criteri(Paraula_i_Freq & x, Paraula_i_Freq & y)
{
  if (x.frequencia > y.frequencia) return true;
  if (x.frequencia == y.frequencia and x.paraula < y.paraula) return true;
  return false;
}

int main()
{
  int n;
  while (cin >> n) {
    int k;
    cin >> k;
    vector<string> w(n);
    for (int i = 0; i < n; ++i) cin >> w[i];
    vector<Paraula_i_Freq> v;
    tractar_paraules(w, v);
    sort(v.begin(), v.end(), criteri);
    escriu_resultat(v, k);
  }
}

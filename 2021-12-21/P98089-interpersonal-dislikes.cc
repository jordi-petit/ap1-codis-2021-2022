#include <iostream>
#include <vector>

using namespace std;

void forma_solucio_identitat(int n, const vector<vector<int>> & manies,
		   vector<int> & solucio, int & suma_manies_solucio)
{
  solucio = vector<int>(n);
  suma_manies_solucio = 0;
  solucio[0] = 0;
  for (int i = 1; i < n; ++i) {
    solucio[i] = i;
    suma_manies_solucio += manies[solucio[i - 1]][solucio[i]];
  }
}

int calcula_bound(int k, vector<int> & sol, int suma, int j, int n,
		  const vector<vector<int>> & manies,
		  vector<bool> & hi_es) {
  //
  // Calcula una fita inferior a la millor suma de manies que es pot
  // aconseguir a partir d'una solucio parcial donada. La fita inferior
  // s'obte sumant, per cada persona que encara no s'ha assegut a la taula
  // (excloent j), la minima mania que li te a qualsevol altre persona
  // que encara no s'ha assegut a la taula (però aquest cop incloent j).
  // Aquesta fita inferior s'utilitzara en l'algorisme de backtracking
  // per podar les branques que no poden millorar la millor solucio que
  // s'ha trobat fins al moment.
  //
  if (k == n) return suma;
  int bound = suma;
  for (int i = 0; i < n; ++i) {
    if (not hi_es[i]) {
      int min_edge = -1;
      for (int l = 0; l < n; ++l) {
        if ((not hi_es[l] or l == j ) and l != i) {
          if (min_edge < 0.0 or manies[l][i] < min_edge) 
            min_edge = manies[l][i];
        }
      }
      bound += min_edge;
    }
  }
  return bound;
}

void troba_sol_rec(int k, vector<int> & sol, int suma, int n,
		   const vector<vector<int>> & manies,
		   vector<int> & sol_m, int & suma_m,
		   vector<bool> & hi_es)
{
  if (k == n) {
    if (suma < suma_m) {
      sol_m = sol;
      suma_m = suma;
    }
  } else {
    for (int i = 1; i < n; ++i) {
      if (not hi_es[i]) {
	sol[k] = i;
	suma += manies[sol[k - 1]][sol[k]];
	hi_es[i] = true;
	int bound = calcula_bound(k + 1, sol, suma, i, n, manies, hi_es);
        if (bound < suma_m)
	  troba_sol_rec(k + 1, sol, suma, n, manies, sol_m, suma_m, hi_es);
	hi_es[i] = false;
	suma -= manies[sol[k - 1]][sol[k]];
	sol[k] = -1;
      }
    }
  }
}
		   


void troba_solucio(int n, const vector<vector<int>> & manies,
		   vector<int> & sol_m, int & suma_m)
{
  vector<int> sol(n, -1);
  sol[0] = 0;
  int suma = 0;
  vector<bool> hi_es(n, false);
  hi_es[0] = true;
  forma_solucio_identitat(n, manies, sol_m, suma_m);
  troba_sol_rec(1, sol, suma, n, manies, sol_m, suma_m, hi_es);
}


int main()
{
  int n;
  while (cin >> n) {
    vector<string> noms(n);
    for (int i = 0; i < n; ++i) cin >> noms[i];
    vector<vector<int>> manies(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
	cin >> manies[i][j];
      }
    }
    vector<int> solucio;
    int suma_manies_solucio;
    troba_solucio(n, manies, solucio, suma_manies_solucio);
    cout << suma_manies_solucio << endl;
    cout << noms[solucio[0]];
    for (int i = 1; i < n; ++i) {
      cout << " " << noms[solucio[i]];
    }
    cout << endl;
  }
}

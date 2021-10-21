#include <iostream>

using namespace std;

void escriu_linia_des(int t, int m, string bloc) {
  if (m > 0) {
    cout << " ";
    escriu_linia_des(t, m - 1, bloc);
  } else {
    if (t > 0) {
      cout << bloc;
      escriu_linia_des(t - 1, 0, bloc);
    }
  }
}

void escriu_linia_desplacada(int t, int m)
{
  escriu_linia_des(t - 1, m, " /\\ ");
  escriu_linia_des(1, 0, " /\\");
  cout << endl;
  escriu_linia_des(t, m, "/__\\");
  cout << endl;
}

void escriu_triangle_desplacat(int t, int m)
{
  if (t > 0) {
    escriu_triangle_desplacat(t - 1, m + 2);
    escriu_linia_desplacada(t, m);
  }
}

void escriu_triangle(int t)
{
  escriu_triangle_desplacat(t, 0);
}

int main() {
  int t;
  cin >> t;
  while (t > 0) {
    escriu_triangle(t);
    cout << endl;
    cin >> t;
  }
}

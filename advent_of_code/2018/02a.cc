#include <iostream>

using namespace std;

int main() {
  const int N = 'z' - 'a' + 1;
  int xs[N] = {};
  int n2 = 0, n3 = 0;

  char c;
  while (cin.get(c)) {
    if (c >= 'a' && c <= 'z') {
      ++xs[c - 'a'];
    } else {
      int f2 = 0, f3 = 0;
      for (int i = 0; i < N; i++) {
        f2 |= xs[i] == 2;
        f3 |= xs[i] == 3;
        xs[i] = 0;
      }
      n2 += f2;
      n3 += f3;
    }
  }

  cout << n2 * n3 <<  endl;
  return 0;
}

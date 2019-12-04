#include <iostream>
#include <string>

using namespace std;

int main() {
  int acc = 0;

  int n;
  while (cin >> n) {
    acc += n;
  }

  cout << acc << endl;
  return 0;
}

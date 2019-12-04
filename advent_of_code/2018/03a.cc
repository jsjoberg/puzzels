#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  char field[1000][1000] = {};
  int acc = 0;

  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    char c;
    int x, y, dx, dy;
    ss.ignore(80, '@');
    ss >> x >> c >> y >> c >> dx >> c >> dy;
    for (int i = x; i < x + dx; i++) {
      for (int j = y; j < y + dy; j++) {
        if (field[i][j] == 1) {
          ++acc;
        }
        ++field[i][j];
      }
    }
  }

  cout << acc << endl;
  return 0;
}

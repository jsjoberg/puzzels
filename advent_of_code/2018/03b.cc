#include <iostream>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main() {
  int field[1000][1000] = {};
  set<int> ids;

  string line;
  while (getline(cin, line)) {
    stringstream ss(line);
    char c;
    int id, x, y, dx, dy;
    ss >> c >> id >> c >> x >> c >> y >> c >> dx >> c >> dy;
    bool cand = true;
    for (int i = x; i < x + dx; i++) {
      for (int j = y; j < y + dy; j++) {
        if (field[i][j] != 0) {
          cand = false;
          ids.erase(field[i][j]);
        }
        field[i][j] = id;
      }
    }
    if (cand) {
      ids.insert(id);
    }
  }

  if (ids.size() != 1) {
    return 1;
  }

  cout << *ids.begin() << endl;
  return 0;
}

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> lines;

  string line;
  while (getline(cin, line)) {
    lines.push_back(line);
  }

  for (int i = 0; i < lines.size(); i++) {
    for (int j = i + 1; j < lines.size(); j++) {
      bool hit = false;
      int diff = 0;
      for (int k = 0; k < lines[i].length(); k++) {
        if (lines[i][k] != lines[j][k]) {
          if (hit) {
            hit = false;
            break;
          } else {
            hit = true;
            diff = k;
          }
        }
      }
      if (hit) {
        cout << lines[i].erase(diff, 1) << endl;
        return 0;
      }
    }
  }

  return 1;
}

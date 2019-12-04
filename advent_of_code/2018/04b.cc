#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

int main() {
  vector<string> lines;
  {
    string line;
    while (getline(cin, line)) {
      lines.insert(lower_bound(lines.begin(), lines.end(), line), line);
    }
  }

  vector<map<int,int>> vs(60);
  int start, id, winner, minute;
  int cand = -1;
  for (string line: lines) {
    stringstream ss(line);
    if (line[19] == 'G') {
      ss.ignore(80, '#');
      ss >> id;
    } else if (line[19] == 'f') {
      ss.ignore(80, ':');
      ss >> start;
    } else if (line[19] == 'w') {
      int end;
      ss.ignore(80, ':');
      ss >> end;
      for (int i = start; i < end; ++i) {
        if (++vs[i][id] > cand) {
          cand = vs[i][id];
          winner = id;
          minute = i;
        }
      }
    }
  }

  cout << winner * minute << endl;

  return 0;
}

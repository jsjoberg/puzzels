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

  int winner;
  {
    map<int, int> gs;
    int id, asleep, longest = -1;
    for (string line: lines) {
      stringstream ss(line);
      if (line[19] == 'G') {
        ss.ignore(80, '#');
        ss >> id;
      } else if (line[19] == 'f') {
        ss.ignore(80, ':');
        ss >> asleep;
      } else if (line[19] == 'w') {
        int awake;
        ss.ignore(80, ':');
        ss >> awake;
        int n = awake - asleep;
        if (gs.find(id) != gs.end()) {
          n += gs[id];
        }
        gs[id] = n;
        if (n > longest) {
          longest = n;
          winner = id;
        }
      } else {
        cout << "UNEXPECTED" << endl;
        return 1;
      }
    }
  }

  int minute;
  {
    int frequent = -1;
    int mins[60] = {};
    bool hit = false;
    int start;
    for (string line: lines) {
      stringstream ss(line);
      if (line[19] == 'G') {
        int id;
        ss.ignore(80, '#');
        ss >> id;
        hit = (winner == id);
      } else if (hit) {
        if (line[19] == 'f') {
          ss.ignore(80, ':');
          ss >> start;
        } else if (line[19] == 'w') {
          int end;
          ss.ignore(80, ':');
          ss >> end;
          for (int i = start; i < end; ++i) {
            ++mins[i];
            if (mins[i] > frequent) {
              frequent = mins[i];
              minute = i;
            }
          } 
        }
      }
    }
  }

  cout << winner * minute << endl;

  return 0;
}

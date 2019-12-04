#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

int main() {
  set<int> freqs;
  vector<int> numbers;

  int n;
  while (cin >> n) {
    numbers.push_back(n);
  }

  int i = 0;
  int acc = 0;
  while (!freqs.count(acc)) {
    freqs.insert(acc);
    acc += numbers[i++];
    i %= numbers.size();
  }

  cout << acc << endl;
  return 0;
}

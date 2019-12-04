#include <iostream>
#include <stack>
#include <set>
#include <cctype>

using namespace std;

constexpr bool match(char a, char b) {
  return a == b + 'a' - 'A' || a == b + 'A' - 'a';
}

stack<char> react(stack<char> in, char ignore) {
  stack<char> out;
  while (!in.empty()) {
    char c = in.top();
    in.pop();
    if (c != ignore && c != ignore - 'a' + 'A') {
      if (!out.empty() && match(c, out.top())) {
        out.pop();
      } else {
        out.push(c);
      }
    }
  }
  return out;
}

int main() {
  stack<char> input;
  set<char> seen;

  char c;
  while (cin.get(c)) {
    if (isalpha(c)) {
      input.push(c);
      seen.insert(tolower(c));
    }
  }

  auto passed = react(input, false);
  int small = passed.size();
  for (char skip: seen) {
    int cand = react(passed, skip).size();
    small = min(cand, small);
  }

  cout << small << endl;

  return 0;
}

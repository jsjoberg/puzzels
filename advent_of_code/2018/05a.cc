#include <iostream>
#include <stack>
#include <cctype>

using namespace std;

constexpr bool match(char a, char b) {
  return a == b + 'a' - 'A' || a == b + 'A' - 'a';
}

int main() {
  stack<char> st;

  char c;
  while (cin.get(c)) {
    if (isalpha(c)) {
      if (!st.empty() && match(c, st.top())) {
        st.pop();
      } else {
        st.push(c);
      }
    }
  }

  cout << st.size() << endl;

  return 0;
}

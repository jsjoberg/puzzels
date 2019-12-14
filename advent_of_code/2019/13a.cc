#include <iostream>
#include <map>
#include "src/computer.cc"

int main() {
	computer c(load());
	std::map<std::pair<int, int>, int> m;
	c.run();
	while (c.running()) {
		int x = c.get();
		c.run();
		int y = c.get();
		c.run();
		std::pair<int, int> p = { x, y };
		m[p] = c.get();
		c.run();
	}
	int n = 0;
	for (auto p : m)
		if (p.second == 2)
			++n;
	std::cout << n << "\n";
	return 0;
}

#include <iostream>
#include <map>
#include "src/computer.cc"

int main() {
	computer c(load());
	std::map<std::pair<int, int>, int> m;
	int x = 0, y = 0, d = 0;
	c.run();
	while (c.running()) {
		std::pair<int, int> p = { x, y };
		c.put(m.count(p) ? m[p] : 0);
		c.run();
		m[p] = c.get();
		c.run();
		d = (d + (c.get() ? 3 : 1)) % 4;
		x = x + (d == 1 ? 1 : d == 3 ? -1 : 0);
		y = y + (d == 0 ? 1 : d == 2 ? -1 : 0);
		c.run();
	}
	std::cout << m.size() << "\n";
	return 0;
}

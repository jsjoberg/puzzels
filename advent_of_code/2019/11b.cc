#include <iostream>
#include <map>
#include "src/computer.cc"

int main() {
	computer c(load());
	std::map<std::pair<int, int>, int> m;
	int x = 0, y = 0, d = 0;
	int x_min = 0, y_min = 0;
	int x_max = 0, y_max = 0;
	std::pair<int, int> o = { 0, 0 };
	m[o] = 1;
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
		if (x > x_max) x_max = x;
		if (x < x_min) x_min = x;
		if (y > y_max) y_max = y;
		if (y < y_min) y_min = y;
		c.run();
	}
	for (int i = y_max; i >= y_min; --i) {
		for (int j = x_max; j >= x_min; --j) {
			std::pair<int, int> p = { j, i };
			std::cout << (!m.count(p) ? ' ' : m[p] ? '#' : '.');
		}
		std::cout << "\n";
	}
	return 0;
}

#include <iostream>
#include <limits>
#include <map>
#include "src/computer.cc"

int main() {
	computer c(load());
	std::map<std::pair<int, int>, int> m;
	int x = 0, y = 0, d = 0;
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
		c.run();
	}
	int x_min, y_min;
	int x_max, y_max;
	x_min = y_min = std::numeric_limits<int>::max();
	x_max = y_max = std::numeric_limits<int>::min();
	for (auto kv : m) {
		auto p = kv.first;
		if (p.first > x_max) x_max = p.first;
		if (p.first < x_min) x_min = p.first;
		if (p.second > y_max) y_max = p.second;
		if (p.second < y_min) y_min = p.second;
	}
	for (int i = y_max; i >= y_min; --i) {
		for (int j = x_max; j >= x_min; --j) {
			std::pair<int, int> p = { j, i };
			std::cout << (m.count(p) ? (m[p] ? '#' : '.') : ' ');
		}
		std::cout << "\n";
	}
	return 0;
}

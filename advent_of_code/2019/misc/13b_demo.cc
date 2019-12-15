#include <iostream>
#include <map>
#include <unistd.h>
#include <vector>
#include "../src/computer.cc"

void blit(
	std::map<std::pair<int, int>, int> m,
	std::pair<int, int> min,
	std::pair<int, int> max
) {
	std::cout << "\033[2J\033[1;1H"; // clear screen
	for (int j = min.second; j <= max.second; ++j) {
		for (int i = min.first; i <= max.first; ++i) {
			std::pair<int, int> p = { i, j };
			if (m.count(p)) {
				if (m[p] == 0) std::cout << ' ';
				else if (m[p] == 1) std::cout << '#';
				else if (m[p] == 2) std::cout << 'x';
				else if (m[p] == 3) std::cout << '=';
				else if (m[p] == 4) std::cout << 'o';
				else std::cout << '?';
			} else {
				std::cout << '.';
			}
		}
		std::cout << "\n";
	}
	return;
}

int main() {
	auto prog = load();
	prog[0] = 2;
	computer c(prog);
	std::map<std::pair<int, int>, int> m;
	std::pair<int, int> min = { 0, 0 };
	std::pair<int, int> max = { 0, 0 };
	int ball_x = 0, pad_x = 0;
	int highscore = 0;
	c.run();
	while (c.running()) {
		int x = c.get();
		c.run();
		int y = c.get();
		c.run();
		int d = c.get();
		c.run();
		if (x == -1 && y == 0) {
			highscore = d;
		} else {
			if (x > max.first) max.first = x;
			if (x < min.first) min.first = x;
			if (y > max.second) max.second = y;
			if (y < min.second) min.second = y;
			std::pair<int, int> p = { x, y };
			m[p] = d;
			if (d == 3) pad_x = x;
			else if (d == 4) ball_x = x;
		}
		if (c.reading()) {
			blit(m, min, max);
			c.put((ball_x > pad_x) ? 1 :
			      (ball_x < pad_x) ? -1 : 0);
			usleep(50000);
			c.run();
		}
	}
	std::cout << highscore << "\n";
	return 0;
}

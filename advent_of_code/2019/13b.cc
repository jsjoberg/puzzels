#include <iostream>
#include <map>
#include "src/computer.cc"

int main() {
	auto prog = load();
	prog[0] = 2;
	computer c(prog);
	int pad_x = 0, ball_x = 0;
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
			if (d == 3)
				pad_x = x;
			else if (d == 4)
				ball_x = x;
		}
		if (c.reading()) {
			c.put((ball_x > pad_x) ? 1 :
			      (ball_x < pad_x) ? -1 : 0);
			c.run();
		}
	}
	std::cout << highscore << "\n";
	return 0;
}

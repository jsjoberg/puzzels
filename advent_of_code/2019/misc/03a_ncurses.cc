#include <iostream>
#include <vector>
#include <algorithm>
#include <ncurses.h>
#include <unistd.h>

struct Line {
	int x1, y1, x2, y2;
	Line(int x, int y, int dx, int dy) {
		x1 = std::min(x, x + dx);
		x2 = std::max(x, x + dx);
		y1 = std::min(y, y + dy);
		y2 = std::max(y, y + dy);
	}
	bool intersect(Line l2, int &x, int &y) {
		if (std::max(x1, l2.x1) <= std::min(x2, l2.x2)
			&& std::max(y1, l2.y1) <= std::min(y2, l2.y2)) {
			if (x1 == x2 && l2.x1 != l2.x2) {
				y = l2.y1;
				x = x1;
			} else if (x1 != x2 && l2.x1 == l2.x2) {
				y = y1;
				x = l2.x1;
			} else {
				std::cout << "lur\n";
				return false;
			}
			return x != 0 || y != 0;
		}
		return false;
	}
};

std::vector<Line> load() {
	std::vector<Line> v;
	char c;
	int t, x, y, dx, dy;
	t = 0;
	x = 0;
	y = 0;
	while (std::cin.get(c) && c != '\n') {
		if (c == 'U') {
			dx = 1;
			dy = 0;
		} else if (c == 'R') {
			dx = 0;
			dy = 1;
		} else if (c == 'D') {
			dx = -1;
			dy = 0;
		} else if (c == 'L') {
			dx = 0;
			dy = -1;
		} else if ( c > '9' || c < '0') {
			dx *= t;
			dy *= t;
			v.push_back(Line(x, y, dx, dy));
			x += dx;
			y += dy;
			t = 0;
		} else {
			t = t * 10 + c - '0';
		}
	}
	dx *= t;
	dy *= t;
	v.push_back(Line(x, y, dx, dy));
	return v;
}

int main() {
	initscr();
	cbreak();
	noecho();
	clear();

	int t = 0; // result
	int o = 5; // offset

	auto wire1 = load();
	auto wire2 = load();

	// draw wires
	for (auto wire : { wire1, wire2 }) {
		for (auto it = wire.begin(); it != wire.end(); it++) {
			if (it->x1 == it->x2)
				mvhline(o+it->x1, o+it->y1, 0, it->y2-it->y1);
			else
				mvvline(o+it->x1, o+it->y1, 0, it->x2-it->x1);

			mvaddch(o+it->x1, o+it->y1, '+');
			mvaddch(o+it->x2, o+it->y2, '+');
		}
	}
	mvaddch(o, o, 'o');

	for (auto it = wire1.begin(); it != wire1.end(); it++) {
		for (auto jt = wire2.begin(); jt != wire2.end(); jt++) {
			int x, y;
			if (it->intersect(*jt, x, y)) {
				mvaddch(o+x, o+y, 'X');
				int m = std::abs(x) + std::abs(y);
				if (t == 0 || (m < t && (x != 0 || y != 0))) {
					t = m;
				}
			}
		}
	}
	refresh();
	sleep(5);
	endwin();

	std::cout << t << "\n";
	return 0;
}

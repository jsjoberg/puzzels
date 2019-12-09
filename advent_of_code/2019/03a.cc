#include <algorithm>
#include <iostream>
#include <vector>

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
	dx = 0;
	dy = 0;
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
	int t = 0; // result

	auto wire1 = load();
	auto wire2 = load();

	for (auto l1 : wire1) {
		for (auto l2 : wire2) {
			int x, y;
			if (l1.intersect(l2, x, y)) {
				int m = std::abs(x) + std::abs(y);
				if (t == 0 || m < t) {
					t = m;
				}
			}
		}
	}

	std::cout << t << "\n";
	return 0;
}

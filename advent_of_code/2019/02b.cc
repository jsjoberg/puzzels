#include <iostream>
#include <vector>

std::vector<int> load() {
	std::vector<int> m;
	int t = 0;
	char c;
	while (std::cin.get(c)) {
		if ( c > '9' || c < '0') { 
			m.push_back(t);
			t = 0;
		} else {
			t = t * 10 + c - '0';
		}
	}
	return m;
}

void run(std::vector<int> &m) {
	int pc = 0;
	for (;;) {
		switch (m[pc]) {
			case 1:
				m[m[pc + 3]] = m[m[pc + 1]] + m[m[pc + 2]];
				pc += 4;
				break;
			case 2:
				m[m[pc + 3]] = m[m[pc + 1]] * m[m[pc + 2]];
				pc += 4;
				break;
			case 99:
				return;
				break;
		}
	}
}

int search(std::vector<int> &m) {
	int n, v;
	for (n = 0; n < 100; n++) {
		for (v = 0; v < 100; v++) {
			auto c(m);
			c[1] = n;
			c[2] = v;
			run(c);
			if (c[0] == 19690720)
				return 100 * n + v;
		}
	}
}

int main() {
	auto program = load();
	std::cout << search(program) << "\n";
	return 0;
}

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
	for(;;) {
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

int main() {
	auto program = load();
	program[1] = 12;
	program[2] = 2;
	run(program);
	std::cout << program[0] << "\n";
	return 0;
}

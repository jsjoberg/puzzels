#include <algorithm>
#include <iostream>
#include <vector>
#include <limits>

std::vector<int> load() {
	std::vector<int> m;
	while (std::cin.peek() != EOF) {
		int t;
		std::cin >> t;
		m.push_back(t);
		char c = std::cin.peek();
		if (c == ',')
			std::cin >> c;
	}
	return m;
}

enum states { go, pause, halt };

struct computer {
	int pc;
	int input;
	int output;
	enum states state;
	std::vector<int> m;

	void run();
};

void computer::run() {
	for (;;) {
		int mode1 = m[pc] / 100 % 10;
		int mode2 = m[pc] / 1000 % 10;
		int mode3 = m[pc] / 10000 % 10;
		switch (m[pc] % 100) {
			case 1:
				m[mode3 ? pc + 3 : m[pc + 3]] =
					m[mode1 ? pc + 1 : m[pc + 1]] +
					m[mode2 ? pc + 2 : m[pc + 2]];
				pc += 4;
				break;
			case 2:
				m[mode3 ? pc + 3 : m[pc + 3]] =
					m[mode1 ? pc + 1 : m[pc + 1]] *
					m[mode2 ? pc + 2 : m[pc + 2]];
				pc += 4;
				break;
			case 3:
				if (state == go) {
					state = pause;
					return;
				}
				state = go;
				m[mode1 ? pc + 1 : m[pc + 1]] = input;
				pc += 2;
				break;
			case 4:
				if (state == go) {
					output = m[mode1 ? pc + 1 : m[pc + 1]];
					state = pause;
					return;
				}
				state = go;
				pc += 2;
				break;
			case 5:
				pc = m[mode1 ? pc + 1 : m[pc + 1]]
					? m[mode2 ? pc + 2 : m[pc + 2]] : pc + 3;
				break;
			case 6:
				pc = m[mode1 ? pc + 1 : m[pc + 1]]
					? pc + 3 : m[mode2 ? pc + 2 : m[pc + 2]];
				break;
			case 7:
				m[mode3 ? pc + 3 : m[pc + 3]] =
					m[mode1 ? pc + 1 : m[pc + 1]] <
					m[mode2 ? pc + 2 : m[pc + 2]];
				pc += 4;
				break;
			case 8:
				m[mode3 ? pc + 3 : m[pc + 3]] =
					m[mode1 ? pc + 1 : m[pc + 1]] ==
					m[mode2 ? pc + 2 : m[pc + 2]];
				pc += 4;
				break;
			case 99:
				state = halt;
				return;
				break;
			default:
				std::cerr << "unknown instruction\n";
				state = halt;
				return;
				break;

		}
	}
	return;
}

int main() {
	auto program = load();
	struct computer origo = { 0, 0, 0, go, program };
	std::vector<int> phase = { 5, 6, 7, 8, 9 };
	int max = std::numeric_limits<int>::min();
	struct computer amp[5];
	do {

		for (int i = 0; i < 5; ++i) {
			amp[i] = origo;
			amp[i].run();
			amp[i].input = phase[i];
			amp[i].run();
		}
		for (int k = 0; k != 5;) {
			k = 0;
			for (int i = 0; i < 5; ++i) {
				if (amp[i].state == halt) {
					++k;
				} else {
					amp[i].input = amp[(i + 4) % 5].output;
					amp[i].run();
				}
			}
		}
		if (amp[4].output > max)
			max = amp[4].output;
	} while (std::next_permutation(phase.begin(), phase.end()));
	std::cout << max << "\n";
	return 0;
}

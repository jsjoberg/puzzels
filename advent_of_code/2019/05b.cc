#include <iostream>
#include <vector>

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

std::vector<int> run(std::vector<int> &m, std::vector<int> &input) {
	std::vector<int> output;
	int pc = 0;
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
				m[mode1 ? pc + 1 : m[pc + 1]] = input.back();
				input.pop_back();
				pc += 2;
				break;
			case 4:
				output.push_back(m[mode1 ? pc + 1 : m[pc + 1]]);
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
				return output;
				break;
			default:
				std::cerr << "unknown instruction\n";
				return output;
				break;

		}
	}
	return output;
}

int main() {
	auto program = load();
	std::vector<int> input = {5};
	for (int n : run(program, input))
		if (n != 0)
			std::cout << n << "\n";
	return 0;
}

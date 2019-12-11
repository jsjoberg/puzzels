#include <array>
#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

int main() {
	std::array<char, 25 * 6> buffer;
	const int max = std::numeric_limits<int>::max();
	std::tuple<int, int, int> top = { max, 0, 0 };
	for (int i = 0; std::cin.read(&buffer[0], buffer.size()); ++i) {
		int zero = 0, one = 0, two = 0;
		for (char c : buffer) {
			if (c == '0') ++zero;
			else if (c == '1') ++one;
			else if (c == '2') ++two;
		}
		auto cand = std::get<0>(top);
		if (zero < cand)
			top = { zero, one, two };
	}
	std::cout << std::get<1>(top) * std::get<2>(top) << "\n";
	return 0;
}

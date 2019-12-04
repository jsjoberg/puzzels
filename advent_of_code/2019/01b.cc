#include <iostream>

int main() {
	int acc = 0;
	int n;
	while (std::cin >> n) {
		for(;;) {
			n = n / 3 - 2;
			if (n <= 0) break;
			acc += n;
		}
	}
	std::cout << acc << "\n";
	return 0;
}

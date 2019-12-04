#include <iostream>

int main() {
	int acc = 0;
	int n;
	while (std::cin >> n)
		acc += n / 3 - 2;
	std::cout << acc << "\n";
	return 0;
}

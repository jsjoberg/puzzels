#include <iostream>

bool adjacent(int n) {
	int prev = n % 10;
	while (n /= 10) {
		int next = n % 10;
		if (prev == next)
			return true;
		else
			prev = next;
	}
	return false;
}

bool increasing(int n) {
	int prev = n % 10;
	while (n /= 10) {
		int next = n % 10;
		if (prev < next)
			return false;
		prev = next;
	}
	return true;
}

int main() {
	int first, last;
	char divider;
	std::cin >> first >> divider >> last;
	if (divider != '-' || last < first)
		return 1;
	int count = 0;
	for (int cand = first; cand <= last; cand++)
		if (adjacent(cand) && increasing(cand))
			count++;
	std::cout << count << "\n";
	return 0;
}

#include <iostream>

bool adjacent_pair(int n) {
	int prev = n % 10;
	int count = 0;
	while (n /= 10) {
		int next = n % 10;
		if (prev == next) {
			count++;
		} else {
			if (count == 1)
				return true;
			prev = next;
			count = 0;
		}
	}
	return count == 1;
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
		if (adjacent_pair(cand) && increasing(cand))
			count++;
	std::cout << count << "\n";
	return 0;
}

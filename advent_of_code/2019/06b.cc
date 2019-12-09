#include <iostream>
#include <map>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;

multimap<string, string> load() {
	multimap<string, string> system;
	string line;
	while (getline(cin, line)) {
		string k, v;
		stringstream ss(line);
		getline(ss, k, ')');
		ss >> v;
		system.insert({k, v});
	}
	return system;
}

int pathfinder(multimap<string, string> &system, string body, int n) {
	auto orbit = system.equal_range(body);
	int i = 0;
	int j = 0;
	for (auto it = orbit.first; it != orbit.second; ++it) {
		if (it->second == "SAN" || it->second == "YOU")
			return n;
		int k = pathfinder(system, it->second, n + 1);
		i += k;
		if (k)
			++j;
		if (j == 2) {
			i -= n + n;
			break;
		}
	}
	return i;
}

int main() {
	auto system = load();
	cout << pathfinder(system, "COM", 0) << "\n";
	return 0;
}

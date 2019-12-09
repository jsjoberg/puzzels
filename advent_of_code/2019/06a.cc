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

int skywalker(multimap<string, string> &system, string body, int i) {
	int j = 0;
	auto orbit = system.equal_range(body);
	for (auto it = orbit.first; it != orbit.second; ++it)
		j += skywalker(system, it->second, i + 1);
	return i + j;
}

int main() {
	auto system = load();
	cout << skywalker(system, "COM", 0) << "\n";
	return 0;
}

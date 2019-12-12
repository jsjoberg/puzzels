#include <iostream>
#include "src/computer.cc"

int main() {
	computer c(load());
	while (c.running()) {
		c.run();
		if (c.reading())
			c.put(2);
		if (c.writing())
			std::cout << c.get() << "\n";
	}
	return 0;
}

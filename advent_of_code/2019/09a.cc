#include <iostream>
#include <map>

std::map<int, long long> load() {
	std::map<int, long long> m;
	for (int i = 0; std::cin.peek() != EOF; ++i) {
		std::cin >> m[i];
		if (std::cin.peek() == ',')
			std::cin.get();
	}
	return m;
}

class computer {
private:
	int index, offset;
	long long output, input;
	std::map<int, long long> memory;
	enum { go, read, write, halt } state;

	int mode(int);
	long long load(int);
	void store(int, long long);
public:
	computer(std::map<int, long long>);
	void run();
	bool running();
	bool reading();
	bool writing();
	long long get();
	void put(long long);
};

computer::computer(std::map<int, long long> program) {
	index = offset = input = output = 0;
	state = go;
	memory = program;
}

void computer::put(long long n) {
	input = n;
}

long long computer::get() {
	return output;
}

bool computer::running() {
	return state != halt;
}

bool computer::reading() {
	return state == read;
}

bool computer::writing() {
	return state == write;
}

int computer::mode(int key) {
	int mask = key == 1 ? 100 : key == 2 ? 1000 : 10000;
	return ((int) memory[index] / mask) % 10;
}

long long computer::load(int key) {
	int addr = 0;
	switch (mode(key)) {
		case 0: // position mode
			addr = memory[index + key];
			break;
		case 1: // immediate mode
			addr = index + key;
			break;
		case 2: // relative mode
			addr = memory[index + key] + offset;
			break;
		default:
			std::cerr << "Illegal load mode\n";
			break;
	}
	return memory.count(addr) ? memory[addr] : 0;
}

void computer::store(int key, long long value) {
	switch (mode(key)) {
		case 0: // position mode
			memory[memory[index + key]] = value;
			break;
		case 2: // relative mode
			memory[memory[index + key] + offset] = value;
			break;
		default:
			std::cerr << "Illegal store mode\n";
			break;
	}
}

void computer::run() {
	for (;;) {
		switch (memory[index] % 100) {
			case 1: // add
				store(3, load(1) + load(2));
				index += 4;
				break;
			case 2: // multiply
				store(3, load(1) * load(2));
				index += 4;
				break;
			case 3: // read
				if (state == go) {
					state = read;
					return; // pause
				}
				state = go; // resume
				store(1, input);
				index += 2;
				break;
			case 4: // write
				if (state == go) {
					output = load(1);
					state = write;
					return; // pause
				}
				state = go; // resume
				index += 2;
				break;
			case 5: // jump if true
				index = load(1) ? load(2) : index + 3;
				break;
			case 6: // jump if false
				index = load(1) ? index + 3 : load(2);
				break;
			case 7: // less then
				store(3, load(1) < load(2));
				index += 4;
				break;
			case 8: // equal
				store(3, load(1) == load(2));
				index += 4;
				break;
			case 9: // relative base
				offset += load(1);
				index += 2;
				break;
			case 99: // halt
				state = halt;
				return;
				break;
			default:
				std::cerr << "Unknown instruction\n";
				state = halt;
				return;
				break;
		}
	}
	return;
}

int main() {
	computer c(load());
	while (c.running()) {
		c.run();
		if (c.reading())
			c.put(1);
		if (c.writing())
			std::cout << c.get() << "\n";
	}
	return 0;
}

#include <array>
#include <iostream>

int main() {
	std::array<char, 25 * 6> buffer, image;
	image.fill('2');
	while (std::cin.read(&buffer[0], buffer.size()))
		for (auto i = 0u; i < buffer.size(); ++i)
			if (image[i] == '2')
				image[i] = buffer[i];
	for (auto i = 0u; i < image.size(); ++i) {
		std::cout << (image[i] == '1' ? '#' : ' ');
		if (i % 25 == 24) std::cout << '\n';
	}
	return 0;
}

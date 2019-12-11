CXX = g++
CXXFLAGS = -Wall -Wextra -march=native -Ofast -pipe -std=c++17

all: 01a 01b 02a 02b 03a 03b 04a 04b 05a 05b 06a 06b 07a 07b 08a 08b
 : %.o
%.o: %.cc

.PHONEY: test clean

test:
	./tests/suit.bash

clean:
	rm -f ???


CXXFLAGS = -Wall -O2 -g -std=c++11

all: 01a 01b 02a 02b 03a 04a 04b 05a 05b 06a 06b 07a 07b
%: %.o
%.o: %.cc

.PHONEY: test clean

test:
	./tests/suit.bash

clean:
	rm -f ???


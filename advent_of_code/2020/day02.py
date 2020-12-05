import re

def validate(s):
    m = re.match("^(\d+)-(\d+) (\w): (\w+)", s)
    a, b, c, d = m.groups()
    return int(a) <= d.count(c) <= int(b)

def part1(data):
    return sum(validate(line) for line in data)

def validate2(s):
    m = re.match("^(\d+)-(\d+) (\w): (\w+)", s)
    a, b, c, d = m.groups()
    i = int(a) - 1
    j = int(b) - 1
    x = d[i] == c
    y = d[j] == c
    return x ^ y

def part2(data):
    return sum(validate2(line) for line in data)

if __name__ == "__main__":
    import sys
    print(part1(sys.stdin))
    #print(part2(sys.stdin))

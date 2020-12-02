#!/usr/bin/env python3

import re

def validate(s):
    m = re.match("^(\d+)-(\d+) (\w): (\w+)", s)
    a, b, c, d = m.groups()
    i = int(a) - 1
    j = int(b) - 1
    x = d[i] == c
    y = d[j] == c
    return x ^ y

def main():
    f = open("input.txt", "r")
    n = 0
    for line in f.readlines():
        if validate(line):
            n += 1
    print(n)

if __name__ == "__main__":
    main()

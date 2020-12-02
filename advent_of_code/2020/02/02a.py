#!/usr/bin/env python3

import re

def validate(s):
    m = re.match("^(\d+)-(\d+) (\w): (\w+)", s)
    a, b, c, d = m.groups()
    i = int(a)
    j = int(b)
    k = d.count(c)
    return i <= k <= j

def main():
    f = open("input.txt", "r")
    n = 0
    for line in f.readlines():
        if validate(line):
            n += 1
    print(n)

if __name__ == "__main__":
    main()

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

if __name__ == "__main__":
    print(sum(validate(line) for line in open("input.txt")))

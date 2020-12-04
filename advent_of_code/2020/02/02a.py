#!/usr/bin/env python3

import re

def validate(s):
    m = re.match("^(\d+)-(\d+) (\w): (\w+)", s)
    a, b, c, d = m.groups()
    return int(a) <= d.count(c) <= int(b)

if __name__ == "__main__":
    print(sum(validate(line) for line in open("input.txt")))

#!/usr/bin/env python3

def pps():
    pp = set()
    for line in open("input.txt"):
        for s in line.split():
            pp.add(s.split(":")[0])
        if not line.strip():
            yield pp
            pp.clear()
    yield pp

if __name__ == "__main__":
    keys = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}
    print(sum(all(k in pp for k in keys) for pp in pps()))

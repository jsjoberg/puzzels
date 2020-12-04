#!/usr/bin/env python3

import re

def pps():
    pp = {}
    for line in open("input.txt"):
        for s in line.split():
            k, v = s.split(":")
            pp[k] = v
        if not line.strip():
            yield pp
            pp.clear()
    yield pp

def hgt(v):
    value = v[:-2]
    unit = v[-2:]
    if unit == "cm":
        return 150 <= int(value) <= 193
    if unit == "in":
        return 59 <= int(value) <= 76
    return False

def ecl(v):
    return v in {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"}

def rules(pp):
    rules = {
        "byr": lambda v: 1920 <= int(v) <= 2002,
        "iyr": lambda v: 2010 <= int(v) <= 2020,
        "eyr": lambda v: 2020 <= int(v) <= 2030,
        "hgt": hgt,
        "hcl": lambda v: re.match(r"^#[\da-fA-F]{6}$", v),
        "ecl": ecl,
        "pid": lambda v: re.match(r"^\d{9}$", v),
        "cid": lambda _: True
    }
    return all(rules[k](v) for k, v in pp.items())

def required_keys(pp):
    keys = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}
    return all(k in pp for k in keys)

if __name__ == "__main__":
    print(sum(required_keys(pp) and rules(pp) for pp in pps()))

#!/usr/bin/env python3

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
    return (unit == "cm" and 150 <= int(value) <= 193) or \
            (unit == "in" and 59 <= int(value) <= 76)

def hcl(v):
    zero_to_f = set(hex(x)[2:] for x in range(16))
    return len(v) == 7 and v[0] == "#" and \
        all(c in zero_to_f for c in v[1:])

def pid(v):
    zero_to_nine = set(map(str, range(10)))
    return len(v) == 9 and all(c in zero_to_nine for c in v)

def ecl(v):
    return v in {"amb", "blu", "brn", "gry", "grn", "hzl", "oth"}

def during(v, start, stop):
    return len(v) == 4 and start <= int(v) <= stop

def rules(x):
    rules = {
        "byr": lambda v: during(v, 1920, 2002),
        "iyr": lambda v: during(v, 2010, 2020),
        "eyr": lambda v: during(v, 2020, 2030),
        "hgt": hgt,
        "hcl": hcl,
        "ecl": ecl,
        "pid": pid,
        "cid": lambda _: True
    }
    return all(rules[k](v) for k, v in x.items())

def required_keys(pp):
    keys = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}
    return all(k in pp for k in keys)

if __name__ == "__main__":
    print(sum(required_keys(x) and rules(x) for x in pps()))

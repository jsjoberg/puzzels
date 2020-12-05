import re

def pps(data):
    pp = set()
    for line in data:
        for s in line.split():
            pp.add(s.split(":")[0])
        if not line.strip():
            yield pp
            pp.clear()
    yield pp

def part1(data):
    keys = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"}
    return sum(all(k in pp for k in keys) for pp in pps(data))

def pps2(data):
    pp = {}
    for line in data:
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

def part2(data):
    return sum(required_keys(pp) and rules(pp) for pp in pps2(data))

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

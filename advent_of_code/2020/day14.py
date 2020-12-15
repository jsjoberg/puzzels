import re
from itertools import combinations

def part1(data):
    mem = {}
    one_mask = 0
    zero_mask = 0
    for l in data:
        if l[0:4] == "mask":
            zero_mask = 0
            one_mask = 0
            for c in l[7:-1]:
                zero_mask <<= 1
                one_mask <<= 1
                zero_mask += 1
                if c == "0":
                    zero_mask -= 1
                elif c == "1":
                    one_mask += 1
        else:
            m = re.match("^mem\[(\d+)\] = (\d+)$", l)
            key, val = m.groups()
            key = int(key)
            val = int(val)
            val |= one_mask
            val &= zero_mask
            mem[key] = val
    return sum(mem.values())

def addresses(key, xs):
    for i in range(len(xs) + 1):
        for ks in combinations(xs, i):
            res = key
            for k in ks:
                res |= k
            yield res

def part2(data):
    mem = {}
    one_mask = 0
    x_mask = 0
    xs = []
    for l in data:
        if l[0:4] == "mask":
            one_mask = 0
            x_mask = 0
            i = 1 << 35
            xs.clear()
            for c in l[7:-1]:
                one_mask <<= 1
                x_mask <<= 1
                x_mask += 1
                if c == "1":
                    one_mask += 1
                elif c == "X":
                    x_mask -= 1
                    xs.append(i)
                i >>= 1
        else:
            m = re.match("^mem\[(\d+)\] = (\d+)$", l)
            key, val = m.groups()
            key = int(key)
            val = int(val)
            key &= x_mask
            key |= one_mask
            for adr in addresses(key, xs):
                mem[adr] = val
    return sum(mem.values())

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

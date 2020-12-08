from collections import defaultdict

def content(data):
    d = defaultdict(set, {})
    for line in data:
        ws = line.split()
        a = (ws[0], ws[1])
        for x,y,z,_ in zip(*[iter(ws[4:])]*4):
            n = int(x)
            b = (y, z)
            d[a] = {(n,b),}.union(d[a])
    return d

def find(d, a):
    if a == ("shiny", "gold"):
        return True
    if a in d:
        return any(find(d,b) for _,b in d[a])
    else:
        return False

def part1(data):
    d = content(data)
    return sum(find(d, k) for k in d.keys()) - 1

def count(d, a):
    return 1 + sum(x * count(d, y) for x, y in d[a])

def part2(data):
    d = content(data)
    return count(d, ("shiny", "gold")) - 1

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

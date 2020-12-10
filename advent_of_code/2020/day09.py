def isHit(ns, x):
    for i, n in enumerate(ns):
        for m in ns[i:]:
            if x == n + m:
                return False
    return True

def part1(data):
    ns = [int(next(data)) for _ in range(25)]
    for l in data:
        n = int(l)
        if isHit(ns, n):
            return n
        ns.pop(0)
        ns.append(n)

def part2(data):
    lines = tuple(data)
    target = part1(iter(lines))
    ns = tuple(int(l) for l in lines)
    x = y = 0
    for i in range(len(ns)):
        acc = 0
        j = i
        while acc < target:
            acc += ns[j]
            if acc == target and j - i > y - x:
               x = i
               y = j
            j += 1
    return min(ns[x:y]) + max(ns[x:y])

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

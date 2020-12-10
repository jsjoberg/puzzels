def part1(data):
    ns = sorted(int(l) for l in data)
    ns = [0] + ns + [ns[-1] + 3]
    ones = 0
    threes = 0
    for i in range(len(ns) - 1):
        diff = ns[i + 1] - ns[i]
        if diff == 1:
            ones += 1
        elif diff == 3:
            threes += 1
    return ones * threes

if __name__ == "__main__":
    import sys
    print(part1(sys.stdin))

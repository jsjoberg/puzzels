def part1(data):
    ns = sorted(int(l) for l in data)
    end = ns[-1] + 3
    ones = 0
    threes = 0
    for a, b in zip([0]+ns, ns+[end]):
        diff = b - a
        if diff == 1:
            ones += 1
        elif diff == 3:
            threes += 1
    return ones * threes

if __name__ == "__main__":
    import sys
    print(part1(sys.stdin))

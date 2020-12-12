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

def part2(data):
    # Thank you Nunki3 for posting this hint!
    # https://old.reddit.com/r/adventofcode/comments/kacdbl/2020_day_10c_part_2_no_clue_how_to_begin/gf9lzhd/
    ns = sorted(int(l) for l in data)
    ns = [0] + ns + [ns[-1] + 3]
    a = 1
    b = 0
    c = 0
    d = 0
    for i in range(len(ns) - 3):
        if ns[i+1] - ns[i] <= 3:
            b += a
        if ns[i+2] - ns[i] <= 3:
            c += a
        if ns[i+3] - ns[i] <= 3:
            d += a
        a, b, c, d = b, c, d, 0
    return a + b

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

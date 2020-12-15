def part1(data):
    t = int(data.readline())
    bs = []
    for s in data.readline().split(","):
        if s != "x":
            bs.append(int(s))
    i = 0
    x = 0
    while True:
        for b in bs:
            if (t + i) % b == 0:
                x = b
                break
        else:
            i += 1
            continue
        break
    return x * i

if __name__ == "__main__":
    import sys
    print(part1(sys.stdin))
    #print(part2(sys.stdin))

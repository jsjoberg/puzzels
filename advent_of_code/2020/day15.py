def play(data, limit):
    d = {}
    p = 0
    ns = data.readline().split(",")
    for i, n in enumerate(map(int, ns), 1):
        p = n
        d[n] = i
    for i in range(len(ns), limit):
        v = i - d.get(p, i)
        d[p] = i
        p = v
    return p

def part1(data):
    return play(data, 2020)

def part2(data):
    return play(data, 30000000)

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

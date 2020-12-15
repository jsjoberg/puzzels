def speak(d, i, n):
    if n not in d:
        d[n] = i
        return 0
    else:
        t = i - d[n]
        d[n] = i
        return t

def play(data, limit):
    ns = data.readline().split(",")
    d = {}
    x = 0
    i = 1
    n = int(ns[0])
    for s in ns[1:]:
        d[n] = i
        n = int(s)
        i += 1
    while i < limit:
        n = speak(d, i, n)
        i += 1
    return n

def part1(data):
    return play(data, 2020)

def part2(data):
    return play(data, 30000000)

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

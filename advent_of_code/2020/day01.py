def part1(data):
    xs = tuple(map(int, data))
    for i, x in enumerate(xs):
        for y in xs[i + 1:]:
            if x + y == 2020:
                return x * y

def part2(data):
    xs = tuple(map(int, data))
    for i, x in enumerate(xs):
        a = 2020 - x
        for j, y in enumerate(xs[i + 1:], i + 1):
            b = a - y
            if b < 0:
                continue
            for z in xs[j:]:
                if b == z:
                    return x * y * z

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

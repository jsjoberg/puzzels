def part1(data):
    xs = tuple(map(int, data))
    for i, x in enumerate(xs):
        for y in xs[i + 1:]:
            if x + y == 2020:
                return x * y

def part2(data):
    xs = tuple(map(int, data))
    for i, x in enumerate(xs):
        for j, y in enumerate(xs[i + 1:], i + 1):
            for z in xs[j:]:
                if x + y + z == 2020:
                    return x * y * z

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

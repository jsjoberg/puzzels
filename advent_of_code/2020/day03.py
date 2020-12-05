def tree(i, n, l):
    cols = len(l) - 1
    j = (i * n) % cols
    return l[j] == "#"

def part1(data):
    return sum(tree(i, 3, l) for i, l in enumerate(data))

def part2(data):
    a = b = c = d = e = 0
    for i, l in enumerate(data):
        if tree(i, 1, l):
            a += 1
            if i % 2 == 0: e += 1
        if tree(i, 3, l): b += 1
        if tree(i, 5, l): c += 1
        if tree(i, 7, l): d += 1
    return a * b * c * d * e

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

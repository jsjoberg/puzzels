def groups(data):
    ys = []
    for line in data:
        xs = set()
        for c in line:
            if "a" <= c <= "z":
                xs.add(c)
        if xs:
            ys.append(xs)
        else:
            yield ys
            ys.clear()
    yield ys

def count(data, combo):
    acc = 0
    for group in groups(data):
        u = group[0]
        for n in group[1:]:
            u = combo(u, n)
        acc += len(u)
    return acc

def part1(data):
    return count(data, lambda a, b: a | b)

def part2(data):
    return count(data, lambda a, b: a & b)

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

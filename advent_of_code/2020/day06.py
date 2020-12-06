def groups(data):
    group = []
    for line in data:
        row = set()
        for c in line:
            if "a" <= c <= "z":
                row.add(c)
        if row:
            group.append(row)
        else:
            yield group
            group.clear()
    yield group

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

def see(area, i, j):
    mi = len(area)
    mj = len(area[0])
    dis = (-1, -1, -1,  0, 0,  1, 1, 1)
    djs = (-1,  0,  1, -1, 1, -1, 0, 1)
    n = 0
    for di, dj in zip(dis, djs):
        if (0 <= i+di < mi and
            0 <= j+dj < mj and
            area[i+di][j+dj] == 2):
            n += 1
    return n

def see2(area, i, j):
    mi = len(area)
    mj = len(area[0])
    dis = (-1, -1, -1,  0, 0,  1, 1, 1)
    djs = (-1,  0,  1, -1, 1, -1, 0, 1)
    n = 0
    for di, dj in zip(dis, djs):
        s = 1
        while (0 <= i+di*s < mi and
               0 <= j+dj*s < mj and
               area[i+di*s][j+dj*s] == 0):
            s += 1
        if (0 <= i+di*s < mi and
            0 <= j+dj*s < mj and
            area[i+di*s][j+dj*s] == 2):
            n += 1
    return n

def tick(area, area2, fn, n):
    for i in range(len(area)):
        for j in range(len(area[0])):
            area2[i][j] = area[i][j]
            if area[i][j] == 1:
                if fn(area, i, j) == 0:
                    area2[i][j] = 2
            elif area[i][j] == 2:
                if fn(area, i, j) >= n:
                    area2[i][j] = 1
    return area2, area

def cmp(area, area2):
    for a, b in zip(area, area2):
        for i, j in zip(a, b):
            if i != j:
                return False
    return True

def start(area, fn, x):
    area2 = [a.copy() for a in area]
    while True:
        area, area2 = tick(area, area2, fn, x)
        if cmp(area, area2):
           break
    n = 0
    for a in area:
        for x in a:
            if x == 2:
                n += 1
    return n

def parse(data):
    return [[1 if c == "L" else 0 for c in l] for l in data]

def part1(data):
    area = parse(data)
    return start(area, see, 4)

def part2(data):
    area = parse(data)
    return start(area, see2, 5)

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

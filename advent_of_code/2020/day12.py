def part1(data):
    d = 0
    x = 0
    y = 0
    for l in data:
        a = l[0]
        n = int(l[1:])
        if a == "L":
            d = (d + (n // 90) * 3) % 4
        elif a == "R":
            d = (d + n // 90) % 4
        elif a == "N":
            x -= n
        elif a == "E":
            y += n
        elif a == "S":
            x += n
        elif a == "W":
            y -= n
        elif a == "F":
            if d == 0:
                y += n
            elif d == 1:
                x += n
            elif d == 2:
                y -= n
            elif d == 3:
                x -= n
    return abs(x) + abs(y)

def part2(data):
    x = 0
    y = 0
    wx = 10
    wy = 1
    for l in data:
        a = l[0]
        n = int(l[1:])
        if a == "L":
            for i in range(n // 90):
                wx, wy = -wy, wx
        elif a == "R":
            for i in range(n // 90):
                wx, wy = wy, -wx
        elif a == "N":
            wy += n
        elif a == "E":
            wx += n
        elif a == "S":
            wy -= n
        elif a == "W":
            wx -= n
        elif a == "F":
            x += n * wx
            y += n * wy
    return abs(x) + abs(y)

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

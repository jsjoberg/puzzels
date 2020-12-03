#!/usr/bin/env python3

if __name__ == "__main__":
    f = open("input.txt", "r")
    hs = [[c == "#" for c in l] for l in f.readlines()]
    cols = len(hs[0]) - 1
    a1 = a2 = a3 = a4 = a5 = 0
    for i in range(1, len(hs)):
        row = hs[i]
        if row[i % cols]:
            if i % 2 == 0:
                a5 += 1
            a1 += 1
        if row[(i * 3) % cols]:
            a2 += 1
        if row[(i * 5) % cols]:
            a3 += 1
        if row[(i * 7) % cols]:
            a4 += 1
    print(a1 * a2 * a3 * a4 * a5)

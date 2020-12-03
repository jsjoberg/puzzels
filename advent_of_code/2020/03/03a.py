#!/usr/bin/env python3

if __name__ == "__main__":
    f = open("input.txt", "r")
    hs = [[c == "#" for c in l] for l in f.readlines()]
    cols = len(hs[0]) - 1
    acc = 0
    for i in range(1, len(hs)):
        if hs[i][(i * 3) % cols]:
            acc += 1
    print(acc)

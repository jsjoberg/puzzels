#!/usr/bin/env python3

if __name__ == "__main__":
    f = open("input.txt")
    ids = set()
    for l in f:
        row_min = 0
        row_max = 128
        col_min = 0
        col_max = 8
        for c in l:
            if c == "F":
                row_max -= (row_max - row_min) // 2
            elif c == "B":
                row_min += (row_max - row_min) // 2
            elif c == "L":
                col_max -= (col_max - col_min) // 2
            elif c == "R":
                col_min += (col_max - col_min) // 2
            else:
                n = row_min * 8 + col_min
                ids.add(n)
    for i in range(min(ids), max(ids)):
        if i not in ids:
            print(i)
            break

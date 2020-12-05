#!/usr/bin/env python3

def tree(i, n, l):
    cols = len(l) - 1
    j = (i * n) % cols
    return l[j] == "#"

if __name__ == "__main__":
    a = b = c = d = e = 0
    for i, l in enumerate(open("input.txt")):
        if tree(i, 1, l):
            a += 1
            if i % 2 == 0: e += 1
        if tree(i, 3, l): b += 1
        if tree(i, 5, l): c += 1
        if tree(i, 7, l): d += 1
    print(a * b * c * d * e)

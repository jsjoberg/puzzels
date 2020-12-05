#!/usr/bin/env python3

def tree(i, l):
    cols = len(l) - 1
    j = (i * 3) % cols
    return l[j] == "#"

if __name__ == "__main__":
    print(sum(tree(i, l) for i, l in enumerate(open("input.txt"))))

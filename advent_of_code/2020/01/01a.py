#!/usr/bin/env python3

def main():
    f = open("input.txt")
    xs = list(map(int, f.readlines()))
    for i, x in enumerate(xs):
        for y in xs[i + 1:]:
            if x + y == 2020:
                print(x * y)
                return

if __name__ == "__main__":
    main()

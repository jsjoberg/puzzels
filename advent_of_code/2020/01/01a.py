#!/usr/bin/env python3

def main():
    xs = tuple(map(int, open("input.txt")))
    for i, x in enumerate(xs):
        for y in xs[i + 1:]:
            if x + y == 2020:
                print(x * y)
                return

if __name__ == "__main__":
    main()

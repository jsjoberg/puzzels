#!/usr/bin/env python3

def main():
    xs = tuple(map(int, open("input.txt")))
    for i, x in enumerate(xs):
        for j, y in enumerate(xs[i + 1:]):
            for z in xs[i + j + 1:]:
                if x + y + z == 2020:
                    print(x * y * z)
                    return

if __name__ == "__main__":
    main()

def seats(data):
    for line in data:
        row_min = 0
        row_max = 128
        col_min = 0
        col_max = 8
        for c in line:
            if c == "F":
                row_max -= (row_max - row_min) // 2
            elif c == "B":
                row_min += (row_max - row_min) // 2
            elif c == "L":
                col_max -= (col_max - col_min) // 2
            elif c == "R":
                col_min += (col_max - col_min) // 2
            else:
                yield row_min * 8 + col_min

def part1(data):
    return max(seats(data))

def part2(data):
    found = set(i for i in seats(data))
    for i in range(min(found), max(found)):
        if i not in found:
            return i

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

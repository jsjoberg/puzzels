import time
from statistics import median

import day01, day02, day03, day04, day05
import day06, day07, day08, day09, day10
import day11, day12, day13, day14, day15

class Test:
    def __init__(self):
        self.acc_min = 0
        self.acc_max = 0
        self.acc_mid = 0
        print("            runs      min   median      max (ms)")
        self.run(day01.part1, 319531)
        self.run(day01.part2, 244300320)
        self.run(day02.part1, 517)
        self.run(day02.part2, 284)
        self.run(day03.part1, 254)
        self.run(day03.part2, 1666768320)
        self.run(day04.part1, 226)
        self.run(day04.part2, 160)
        self.run(day05.part1, 874)
        self.run(day05.part2, 594)
        self.run(day06.part1, 6590)
        self.run(day06.part2, 3288)
        self.run(day07.part1, 179)
        self.run(day07.part2, 18925)
        self.run(day08.part1, 1753)
        self.run(day08.part2, 733)
        self.run(day09.part1, 31161678)
        self.run(day09.part2, 5453868)
        self.run(day10.part1, 1690)
        self.run(day10.part2, 5289227976704)
        self.run(day11.part1, 2270)
        self.run(day11.part2, 2042)
        self.run(day12.part1, 1148)
        self.run(day12.part2, 52203)
        self.run(day13.part1, 138)
        #run(day13.part2, )
        print("day13 part2 TODO")
        self.run(day14.part1, 4297467072083)
        self.run(day14.part2, 5030603328768)
        self.run(day15.part1, 1522)
        self.run(day15.part2, 18234)
        print("ok, total:       " , end="")
        print(f"{self.acc_min:8.1f} {self.acc_mid:8.1f} {self.acc_max:8.1f}")

    def run(self, fn, exp):
        ts = []
        reps = 10
        acc = 0
        input_filename = f"input/{fn.__module__[-2:]}"
        for i in range(reps):
            start = time.perf_counter_ns()
            assert fn(open(input_filename)) == exp
            stop = time.perf_counter_ns()
            diff = stop - start
            ts.append(diff)
            acc += diff
            if acc > 2e9:
                reps = i + 1
                break
        ms_min = min(ts) / 1e6
        ms_max = max(ts) / 1e6
        ms_mid = median(ts) / 1e6
        print(f"{fn.__module__} {fn.__name__} ({reps:2}) ", end="")
        print(f"{ms_min:8.1f} {ms_mid:8.1f} {ms_max:8.1f}")
        self.acc_min +=  ms_min
        self.acc_max +=  ms_max
        self.acc_mid +=  ms_mid

if __name__ == "__main__":
    Test()

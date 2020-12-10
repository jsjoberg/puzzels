import time

import day01, day02, day03, day04, day05
import day06, day07, day08, day09, day10

if __name__ == "__main__":
    start = time.perf_counter_ns()
    assert day01.part1(open("input/01")) == 319531
    assert day01.part2(open("input/01")) == 244300320
    assert day02.part1(open("input/02")) == 517
    assert day02.part2(open("input/02")) == 284
    assert day03.part1(open("input/03")) == 254
    assert day03.part2(open("input/03")) == 1666768320
    assert day04.part1(open("input/04")) == 226
    assert day04.part2(open("input/04")) == 160
    assert day05.part1(open("input/05")) == 874
    assert day05.part2(open("input/05")) == 594
    assert day06.part1(open("input/06")) == 6590
    assert day06.part2(open("input/06")) == 3288
    assert day07.part1(open("input/07")) == 179
    assert day07.part2(open("input/07")) == 18925
    assert day08.part1(open("input/08")) == 1753
    assert day08.part2(open("input/08")) == 733
    assert day09.part1(open("input/09")) == 31161678
    assert day09.part2(open("input/09")) == 5453868
    assert day10.part1(open("input/10")) == 1690
    stop = time.perf_counter_ns()
    ms = (stop - start) // 1_000_000
    print(f"ok, runtime {ms}ms")

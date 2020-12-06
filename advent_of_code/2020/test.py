import day01, day02, day03, day04, day05
import day06

if __name__ == "__main__":
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
    print("ok")

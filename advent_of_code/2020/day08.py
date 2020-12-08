def load(data):
    code = []
    for line in data:
        inst = line[0:3]
        arg = int(line[4:])
        code.append((inst, arg))
    return code

def vm(code):
    trace = set()
    pc = 0
    acc = 0
    while pc not in trace:
        trace.add(pc)
        inst, arg = code[pc]
        if inst == "acc":
            acc += arg
            pc += 1
        if inst == "jmp":
            pc += arg
        if inst == "nop":
            pc += 1
    return acc

def vm2_runner(code, pc, acc):
    trace = set()
    while pc not in trace:
        trace.add(pc)
        inst, arg = code[pc]
        if inst == "acc":
            acc += arg
            pc += 1
        if inst == "jmp":
            pc += arg
        if inst == "nop":
            pc += 1
        if pc == len(code):
            return acc
    return False

def vm2(code):
    pc = 0
    acc = 0
    trace = set()
    while pc not in trace:
        trace.add(pc)
        inst, arg = code[pc]
        if inst == "acc":
            acc += arg
            pc += 1
        if inst == "jmp":
            code[pc] = ("nop", arg)
            r = vm2_runner(code, pc, acc)
            if r:
                return r
            code[pc] = ("jmp", arg)
            pc += arg
        if inst == "nop":
            code[pc] = ("jmp", arg)
            r = vm2_runner(code, pc, acc)
            if r:
                return r
            code[pc] = ("nop", arg)
            pc += 1
        if pc == len(code):
            return acc
    return False

def part1(data):
    return vm(load(data))

def part2(data):
    return vm2(load(data))

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

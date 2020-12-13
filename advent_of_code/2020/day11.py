class Seat:
    def __init__(self, limit):
        self.neighbors = []
        self.taken = False
        self.change = False
        self.limit = limit

    def add(self, s):
        self.neighbors.append(s)

    def tick(self):
        if (not self.taken and
            not any(s.taken for s in self.neighbors)):
            self.change = True
        if (self.taken and
            sum(s.taken for s in self.neighbors) >= self.limit):
            self.change = False

    def update(self):
        diff = self.taken != self.change
        self.taken = self.change
        return diff

class Area:
    def __init__(self, data):
        xs = [[Seat(4) if c == "L" else None for c in l]
              for l in data]
        self.seats = []
        mi = len(xs)
        mj = len(xs[0])
        dis = (-1, -1, -1,  0, 0,  1, 1, 1)
        djs = (-1,  0,  1, -1, 1, -1, 0, 1)
        for i in range(len(xs)):
            for j in range(len(xs[0])):
                if xs[i][j]:
                    for di, dj in zip(dis, djs):
                        if (0 <= i+di < mi and
                            0 <= j+dj < mj and
                            xs[i+di][j+dj]):
                            xs[i][j].add(xs[i+di][j+dj])
                    self.seats.append(xs[i][j])

    def run(self):
        while True:
            for s in self.seats:
                s.tick()
            f = True
            for s in self.seats:
                f = not s.update() and f
            if f:
                break

    def taken(self):
        return sum(s.taken for s in self.seats)

class Area2(Area):
    def __init__(self, data):
        xs = [[Seat(5) if c == "L" else None for c in l]
              for l in data]
        self.seats = []
        mi = len(xs)
        mj = len(xs[0])
        dis = (-1, -1, -1,  0, 0,  1, 1, 1)
        djs = (-1,  0,  1, -1, 1, -1, 0, 1)
        for i in range(len(xs)):
            for j in range(len(xs[0])):
                if xs[i][j]:
                    for di, dj in zip(dis, djs):
                        s = 1
                        while (0 <= i+di*s < mi and
                            0 <= j+dj*s < mj and
                            not xs[i+di*s][j+dj*s]):
                            s += 1
                        if (0 <= i+di*s < mi and
                            0 <= j+dj*s < mj and
                            xs[i+di*s][j+dj*s]):
                            xs[i][j].add(xs[i+di*s][j+dj*s])
                    self.seats.append(xs[i][j])

def part1(data):
    area = Area(data)
    area.run()
    return area.taken()

def part2(data):
    area = Area2(data)
    area.run()
    return area.taken()

if __name__ == "__main__":
    import sys
    #print(part1(sys.stdin))
    print(part2(sys.stdin))

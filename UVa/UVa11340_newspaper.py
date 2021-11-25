from sys import stdin
getc = stdin.readline
tests = int(getc())
for _ in range(tests):
    chars = int(getc())
    prices = {}
    paid = 0.0
    for _ in range(chars):
        c, p = getc().split()
        p = int(p) / 100.0
        prices[c] = p
    lines = int(getc())
    for _ in range(lines):
        line = getc()
        for a in line:
            if a in prices:
                paid += prices[a]

    print('{:.02f}$'.format(paid))

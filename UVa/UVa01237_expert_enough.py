from sys import stdin
getc = stdin.readline
TC = int(getc())
for i in range(TC):
    if i > 0: print()
    D = int(getc())
    db = []
    for _ in range(D):
        make, L, H = getc().split()
        db.append((make, int(L), int(H)))
    Q = int(getc())
    for _ in range(Q):
        count = 0
        price = int(getc())
        for m, l, h in db:
            if price <= h and price >= l:
                if count == 0:
                    name = m
                count += 1
                if count > 1:
                    break
        if count == 1:
            print(name)
        else:
            print('UNDETERMINED')


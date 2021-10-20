order = 1

while True:
    req, prop = [int(i) for i in input().split()]
    if req == 0:
        break
    if order > 1:
        print()
    for _ in range(req):
        input()
    candidate = ''
    best_comp = 0
    lowest = float('inf')
    for p in range(prop):
        name = input()
        price, met = [float(f) for f in input().split()]
        met = int(met)

        # skip lines of reqs
        for m in range(met):
            input()

        # found new prop with highest requirements met
        if met > best_comp:
            candidate = name
            lowest = price
            best_comp = met
        elif met == best_comp:  # same requirement; check price for tie-breaker
            if price < lowest:
                lowest = price
                candidate = name
    print('RFP #{}'.format(order))
    print(candidate)
    order += 1

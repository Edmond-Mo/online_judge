TC = int(input())
for c in range(1, TC+1):
    input()
    low = 0
    high = 0
    walls = [int(i) for i in input().split()]
    w = 0
    while w < len(walls) - 1:
        if walls[w] > walls[w+1]:
            low += 1
        elif walls[w] < walls[w+1]:
            high += 1
        w += 1
    print("Case {}: {} {}".format(c, high, low))






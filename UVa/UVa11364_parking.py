tests = int(input())
for _ in range(tests):
    n = int(input())
    stores = [int(i) for i in input().split()]
    stores.sort()
    mid = n // 2
    print(stores[mid] - stores[0] + stores[-1] - stores[0] + stores[-1] - stores[mid])




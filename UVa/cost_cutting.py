tests = int(input())
for case in range(tests):
    e = [int(i) for i in input().split()]
    e.sort()
    print('Case {}: {}'.format(case+1, e[1]))

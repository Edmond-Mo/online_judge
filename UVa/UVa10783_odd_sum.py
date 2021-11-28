tc = int(input())
for j in range(1, tc+1):
    a = int(input())
    b = int(input())
    print("Case {}: {}".format(j, sum(i for i in range(a, b+1) if i & 1)))

from sys import stdin
getc = stdin.readline
W = int(getc())
N = int(getc())
area = 0
for _ in range(N):
    w, l = (int(i) for i in getc().split())
    area += w * l
print(area//W)

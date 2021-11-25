import sys

while True:
    N, M = (int(i) for i in sys.stdin.readline().split())
    if M == 0 or N == 0: break

    dup = 0
    setN = set()
    for _ in range(N):
        setN.add(int(sys.stdin.readline()))
    for _ in range(M):
        if int(sys.stdin.readline()) in setN:
            dup += 1
    print(dup)

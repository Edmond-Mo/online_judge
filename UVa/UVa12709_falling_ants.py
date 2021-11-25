from sys import stdin, stdout

while True:
    T = int(stdin.readline())
    if T == 0: break
    ants = []
    for _ in range(T):
        L, W, H = (int(i) for i in stdin.readline().split())
        ants.append((H, L*W*H))
    ants.sort()
    stdout.write(str(ants[-1][1]) + '\n')
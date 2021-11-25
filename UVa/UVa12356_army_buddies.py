from sys import stdin
getc = stdin.readline

while True:
    S, B = (int(i) for i in getc().split())
    if S == 0 and B == 0: break

    # 0th and S+1th are sentienls
    soldiers = [i for i in range(S+2)]
    soldiers[S+1] = 0
    for _ in range(B):
        L, R = (int(i) for i in getc().split())
        for i in range(L, R+1):
            soldiers[i] = 0     # killed
        
        # scan for new left buddy
        left = L - 1
        while left >= 0 and soldiers[left] == 0:
            left -= 1
        if left < 0:
            print('*', end=' ')
        else:
            print('{}'.format(soldiers[left]), end=' ')

        # scan for right buddy
        right = R + 1
        while right <= S and soldiers[right] == 0:
            right += 1
        if right > S:
            print('*')
        else:
            print('{}'.format(soldiers[right]))

    print('-')

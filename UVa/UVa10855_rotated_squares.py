#import pdb
from sys import stdin
getc = stdin.readline

def rotate90cw(mat):
    n = len(mat)

    # transpose matrix
    for i in range(n):
        for j in range(i, n):
            mat[i][j], mat[j][i] = mat[j][i], mat[i][j]

    # reverse rows
    for r in range(n):
        mat[r] = mat[r][::-1]

def compareMat(big, small):
    delta = len(big) - len(small)
    count = 0
    for i in range(delta + 1):
        for j in range(delta + 1):
            same = True
            for r in range(len(small)):
                if small[r] != big[i+r][j:j+len(small)]:
                    same = False
                    break
            if same:
                count += 1 
    return count

while True:
    N, n = (int(i) for i in getc().split())
    if N == 0: break

    bigMat = []
    for _ in range(N):
        bigMat.append(list(getc()[:-1]))
    smallMat = []
    for _ in range(n):
        smallMat.append(list(getc()[:-1]))

    k = compareMat(bigMat, smallMat)
    print('{}'.format(k), end=' ')

    rotate90cw(smallMat)

    k = compareMat(bigMat, smallMat)
    print('{}'.format(k), end=' ')

    rotate90cw(smallMat)

    k = compareMat(bigMat, smallMat)
    print('{}'.format(k), end=' ')

    rotate90cw(smallMat)

    k = compareMat(bigMat, smallMat)
    print('{}'.format(k))

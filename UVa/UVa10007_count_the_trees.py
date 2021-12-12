import math
from sys import stdin, stdout

MAX_N = 620

pt = [[None] * MAX_N for _ in range(MAX_N)]

def pascalTriangle():
    global pt
    for i in range(MAX_N):
        pt[i][0] = pt[i][i] = 1
    for i in range(1, MAX_N - 1):
        for j in range(1, i):
            pt[i][j] = pt[i-1][j] + pt[i-1][j-1]

def main():
    global pt
    pascalTriangle()
    while True:
        n = int(stdin.readline())
        if n == 0:
            break
        cat = pt[n<<1][n] // (n+1)
        stdout.write("{}\n".format(cat * math.factorial(n)))

main()


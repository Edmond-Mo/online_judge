from sys import stdin, stdout

while True:
    try:
        N, A = (int(i) for i in stdin.readline().split())
        total = 0
        for i in range(1, N+1):
            total += i * A ** i
        stdout.write(str(total) + '\n')
    except:
        break
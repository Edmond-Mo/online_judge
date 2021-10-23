from sys import stdin, stdout

DIM = 8
soln = []

def canPlaceHere(r, c, ans):
    for i in range(0, c):
        if ans[i] == r:     # same row
            return False
        if (r + c) == (ans[i] + i):     # right diagonal ( / )
            return False
        if (r - c + DIM - 1) == (ans[i] - i + DIM - 1): # left ( \ )
            return False

    return True

def backtrack(col, ans, qr, qc):
    global soln

    if col == DIM:
        soln.append(ans.copy())
        return

    for row in range(DIM):
        # bypass answer that doesn't have (qr, qc) as part of it
        if col == qc and row != qr:
            continue
        if canPlaceHere(row, col, ans):
            ans[col] = row
            backtrack(col + 1, ans, qr, qc)

def main():
    tc = int(stdin.readline())
    for t in range(1, tc + 1):
        if t > 1:
            stdout.write("\n")
        stdin.readline()    # get rid of blank line
        qr, qc = (int(i) for i in stdin.readline().split())
        ans = [0] * DIM
        stdout.write("SOLN       COLUMN\n")
        stdout.write(" #      1 2 3 4 5 6 7 8\n\n")
        backtrack(0, ans, qr - 1, qc - 1)
        for s in range(len(soln)):
            answer = ' '.join(str(n+1) for n in soln[s])
            stdout.write("{:2}      {}\n".format(s+1, answer))
        soln.clear()

main()

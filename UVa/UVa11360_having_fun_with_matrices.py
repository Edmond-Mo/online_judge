from sys import stdin, stdout

def switch_row(mat, a, b):
    mat[a], mat[b] = mat[b], mat[a]

def switch_col(mat, a, b):
    for row in mat:
        row[a], row[b] = row[b], row[a]

def inc(mat):
    for row in range(len(mat)):
        for col in range(len(mat[0])):
            mat[row][col] += 1
            if mat[row][col] >= 10:
                mat[row][col] -= 10

def dec(mat):
    for row in range(len(mat)):
        for col in range(len(mat[0])):
            mat[row][col] -= 1
            if mat[row][col] < 0:
                mat[row][col] += 10
 
def transpose(mat):
    return [list(t) for t in zip(*mat)]

tc = int(stdin.readline().strip())
for casenum in range(1, tc+1):
    N = int(stdin.readline())
    mat = []
    for _ in range(N):
        row = [int(i) for i in list(stdin.readline().strip())]
        mat.append(row)
    M = int(stdin.readline().strip())
    for _ in range(M):
        op = stdin.readline().strip()
        if op.startswith('row'):
            args = op.split(' ')
            switch_row(mat, int(args[1])-1, int(args[2])-1)
        elif op.startswith('col'):
            args = op.split(' ')
            switch_col(mat, int(args[1])-1, int(args[2])-1)
        elif op == 'inc':
            inc(mat)
        elif op == 'dec':
            dec(mat)
        elif op == 'transpose':
            mat = transpose(mat)
    stdout.write('Case #{}\n'.format(casenum))
    for r in range(N):
        stdout.write(''.join(str(i) for i in mat[r]) + '\n')
    stdout.write('\n')






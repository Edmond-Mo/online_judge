from sys import stdin, stdout

def main():
    tc = int(stdin.readline())
    for _ in range(tc):
        hasEdges = set()
        numEdges = 0
        while True:
            line = stdin.readline().strip()
            if line.startswith('*'):
                break
            numEdges += 1
            line = line.split(',')
            u = line[0][1]
            v = line[1][0]
            hasEdges.add(u)
            hasEdges.add(v)
        vertices = stdin.readline().strip('\n').split(',')
        cc = len(vertices) - numEdges
        acorn = len(vertices) - len(hasEdges)
        trees = cc - acorn
        stdout.write('There are {} tree(s) and {} acorn(s).\n'.format(trees, acorn))

main()
from sys import stdin, stdout

parent = None
rank = None
size = None

def union_find(n):
    global parent
    if parent[n] == n:
        return n
    parent[n] = union_find(parent[n])
    return parent[n]

def union_merge(s1, s2):
    global parent
    global rank
    global size
    p1 = union_find(s1)
    p2 = union_find(s2)
    if p1 == p2:
        return

    if rank[p1] > rank[p2]:
        parent[p2] = p1
        size[p1] += size[p2]
    elif rank[p2] > rank[p1]:
        parent[p1] = p2
        size[p2] += size[p1]
    else:
        parent[p2] = p1
        size[p1] += size[p2]
        rank[p1] += 1


def main():
    global parent
    global rank
    global size

    while True:
        stu, grp = (int(i) for i in stdin.readline().strip('\n').split())
        if stu == 0 and grp == 0:
            break
        parent = [i for i in range(stu)]
        rank = [0] * stu
        size = [1] * stu

        for _ in range(grp):
            g = [int(i) for i in stdin.readline().strip('\n').split()]
            for j in range(1, len(g)-1):
                union_merge(g[j], g[j+1])

        stdout.write('{}\n'.format(size[parent[0]]))

main()

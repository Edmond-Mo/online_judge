dfs_num = []
dfs_low = []
dfs_parent = []
articulation_vertex = []
dfs_num_cntr = 0
dfs_root = 0
root_children = 0

def articulationPointBridge(u, AL):
    global dfs_num, dfs_low, dfs_parent
    global articulation_vertex, dfs_num_cntr, dfs_root, root_children

    dfs_low[u] = dfs_num[u] = dfs_num_cntr
    dfs_num_cntr += 1

    for v in AL[u]:
        if dfs_num[v] == -1:
            dfs_parent[v] = u
            if u == dfs_root:
                root_children += 1

            articulationPointBridge(v, AL)

            if dfs_parent[u] != -1 and dfs_low[v] >= dfs_num[u]:
                articulation_vertex[u] = 1
            dfs_low[u] = min(dfs_low[u], dfs_low[v])
        elif v != dfs_parent[u]:
            dfs_low[u] = min(dfs_low[u], dfs_num[v])

def main():
    global dfs_num, dfs_low, dfs_parent
    global articulation_vertex, dfs_num_cntr, dfs_root, root_children
    while True:
        V = int(input())
        if V == 0:
            break
        V += 1      # 1 based vertice numbers
        AL = [[] for _ in range(V)]
        dfs_num = [-1] * V  # unvisited
        dfs_low = [0] * V
        dfs_parent = [-1] * V
        articulation_vertex = [0] * V
        dfs_num_cntr = 0

        for _ in range(V):
            u, *v = (int(i) for i in input().strip().split())
            if u == 0:
                break
            AL[u].extend(v)
            for dst in v:
                AL[dst].append(u)

        for u in range(1, V):
            if dfs_num[u] == -1:
                dfs_root = u
                root_children = 0
                articulationPointBridge(u, AL)
                if root_children > 1:
                    articulation_vertex[dfs_root] = 1
        print(sum(articulation_vertex))

main()

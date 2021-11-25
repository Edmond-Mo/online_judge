#include <bits/stdc++.h>
using namespace std;

typedef unsigned int u32;
#define INF 0xFFFFFFFF

u32 am[108][108];     // not needed for this particular problem; only for path construction
u32 dist[108][108];   // adj matrix
u32 parent[108][108]; // path parent matrix; also not needed

void dump(u32 a[108][108], int V) {
    printf("dump:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}

void printPath(u32 a[108][108], int i, int j) {
    if (i != j)
        printPath(a, i, a[i][j]);
    printf("path: %d\n", j);
}


int main() {
    int tc = 1;
    while (1) {
        int V, E, Q;
        scanf("%d %d %d", &V, &E, &Q);
        if (V == 0 && E == 0 && Q == 0)
            break;
        if (tc > 1) printf("\n");

        memset(dist, 0xff, sizeof dist); // max u32 value
        memset(am, 0xff, sizeof am); // max u32 value
        for (int i = 0; i < E; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            u--; v--;
            dist[u][v] = (u32)w;
            dist[v][u] = (u32)w;
            am[u][v] = (u32)w;
            am[v][u] = (u32)w;
        }
        
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                parent[i][j] = (u32)i;
            }
            am[i][i] = 0;
            dist[i][i] = 0;
        }

        // Floyd Warshall
        for (int k = 0; k < V; k++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (dist[i][k] == INF || dist[k][j] == INF)
                        continue;
                    // NORMAL floyd-warshall algo for shortest path
                    //u32 newDist = dist[i][k] + dist[k][j];
                    //if (newDist < dist[i][j]) {

                    // This is for MiniMax problems:
                    u32 newMaxDist = max(dist[i][k], dist[k][j]);
                    if (newMaxDist < dist[i][j]) {
                        dist[i][j] = newMaxDist;
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }

//        dump(am, V);
//        dump(dist, V);
//        dump(parent, V);
        printf("Case #%d\n", tc++);

        for (int i = 0; i < Q; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            u--; v--;
            if (dist[u][v] == INF) {
                printf("no path\n");
                continue;
            }

            printf("%d\n", dist[u][v]);
            //printPath(parent, u, v);
#if TRAVERSE_PATH
            u32 lim = 0;
            while (v != u) {
                // edge weight of node pair (p[u][v], v)
                printf("iter: %d [%d]\n", v, am[parent[u][v]][v]);
                if (am[parent[u][v]][v] > lim)
                    lim = am[parent[u][v]][v];
                v = parent[u][v];
            }
            printf("%d\n", lim);
#endif
        }
    }
    return 0;
}


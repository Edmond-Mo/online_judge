#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
    int tc;
    scanf("%d", &tc);
    for (int x = 1; x <= tc; x++) {
        int V, E;
        scanf("%d", &V);
        scanf("%d", &E);
        int AM[V][V];
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                AM[u][v] = INF;
            }
            AM[u][u] = 0;
        }
        for (int e = 0; e < E; e++) {
            int u, v;
            scanf("%d %d", &u, &v);
            AM[u][v] = 1;
            AM[v][u] = 1;
        }
        int start, end;
        scanf("%d %d", &start, &end);
        
        // Floyd-Warshall All-pair shortest paths
        for (int k = 0; k < V; k++)
            for (int u = 0; u < V; u++)
                for (int v = 0; v < V; v++)
                    AM[u][v] = min(AM[u][v], AM[u][k] + AM[k][v]);

        int ans = 0;
        for (int i = 0; i < V; i++) {
            if (i == end)
                continue;
            ans = max(ans, AM[start][i] + AM[i][end]);
        }

        printf("Case %d: %d\n", x, ans);
    }

    return 0;
}

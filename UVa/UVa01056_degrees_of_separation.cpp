#include <bits/stdc++.h>
using namespace std;

#define INF 1e9

int main() {
    int V, E;
    int tc = 1;
    while (1) {
        scanf("%d %d", &V, &E);
        if (V == 0 && E == 0)
            break;
        int AM[V][V];
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                AM[u][v] = INF;
            }
            AM[u][u] = 0;
        }
        char p[200];
        char q[200];
        unordered_map<string, int> m;
        int index = 0;
        for (int e = 0; e < E; e++) {
            scanf("%s %s", p, q);
            string s1 = string(p);
            string s2 = string(q);
            if (m.find(s1) == m.end()) {
                m.emplace(string(p), index);
                index++;
            }
            if (m.find(s2) == m.end()) {
                m.emplace(string(q), index);
                index++;
            }
            AM[m[s1]][m[s2]] = 1;
            AM[m[s2]][m[s1]] = 1;
        }

        // Floyd-Warshall APSP
        for (int k = 0; k < V; k++)
            for (int u = 0; u < V; u++)
                for (int v = 0; v < V; v++)
                    AM[u][v] = min(AM[u][v], AM[u][k] + AM[k][v]);

        int ans = 0;
        bool disconnected = false;
        for (int u = 0; u < V && !disconnected; u++) {
            for (int v = 0; v < V; v++) {
                if (AM[u][v] == INF) {
                    disconnected = true;
                    break;
                }
                ans = max(ans, AM[u][v]);
            }
        }

        if (disconnected)
            printf("Network %d: DISCONNECTED\n\n", tc);
        else
            printf("Network %d: %d\n\n", tc, ans);
        tc++;
    }
    return 0;
}


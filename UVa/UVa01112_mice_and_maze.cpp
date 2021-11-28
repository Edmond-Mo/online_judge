#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9


int main() {
    int tc;
    char line[1000];
    vector<vii> AL;
    vi dist;
    fgets(line, 1000, stdin);
    sscanf(line, "%d", &tc);
    while (tc--) {
        fgets(line, 1000, stdin);    // skip blank line
        int V, E, exit, T;
        fgets(line, 1000, stdin);
        sscanf(line, "%d", &V);
        fgets(line, 1000, stdin);
        sscanf(line, "%d", &exit);
        exit--;     // 0 based index
        fgets(line, 1000, stdin);
        sscanf(line, "%d", &T);
        fgets(line, 1000, stdin);
        sscanf(line, "%d", &E);
        AL.assign(V, vii());
        for (int i = 0; i < E; i++) {
            int u, v, w;
            fgets(line, 1000, stdin);
            sscanf(line, "%d %d %d", &u, &v, &w);
            u--; v--;       // 0 based
            AL[v].emplace_back(u, w); // reverse direction because
                                      // we start from 'exit'
        }

        // Modified Dijkstra's algorithm
        dist.assign(V, INF);
        // store pairs of (dist, vertex)
        priority_queue<ii, vector<ii>, greater<ii>> pq;     // min heap
        pq.emplace(0, exit);    // starting from exit cell 
        dist[exit] = 0;
        while (!pq.empty()) {
            // pair of (dist, vertex)
            auto p = pq.top(); pq.pop();
            int d = p.first;
            int u = p.second;
            if (d > dist[u])   // lazy deletion
                continue;
            // node is pair (vertex, weight)
            for (auto node : AL[u]) {
                int v = node.first;
                int w = node.second;
                if (dist[u] + w < dist[v]) {    // relaxing
                    dist[v] = dist[u] + w;
                    pq.emplace(dist[v], v);
                }
            }
        }

        int escapes = 0;
        for (auto d : dist) {
            if (d <= T)
                escapes++;
        }

        printf("%d\n", escapes);
        if (tc) printf("\n");
    }
    return 0;
}

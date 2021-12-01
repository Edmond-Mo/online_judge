#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define INF 1e9

vector<vii> AL;

// Bellman-Ford: returns true if negative cycle
bool BellmanFord(int V) {
    vi dist(V, INF);
    dist[0] = 0;
    for (int i = 0; i < V - 1; i++) {
        bool modified = false;
        for (int u = 0; u < V; u++) {
            if (dist[u] != INF) {
                for (auto p : AL[u]) {
                    int v = p.first;
                    int w = p.second;
                    if (dist[u] + w < dist[v]) {
                        dist[v] = dist[u] + w;
                        modified = true;
                    }
                }
            }
        }
        if (!modified)
            break;
    }

    bool negCycle = false;
    for (int u = 0; u < V; u++) {
        if (dist[u] != INF) {
            for (auto p : AL[u]) {
                int v = p.first;
                int w = p.second;
                if (dist[u] + w < dist[v]) {
                    negCycle = true;
                }
            }
        }
    }

    return negCycle;
}

int main() {
    int tc;
    scanf("%d", &tc);
    for (int x = 0; x < tc; x++) {
        int V, E;
        scanf("%d %d", &V, &E);
        AL.assign(V, vii());
        for (int e = 0; e < E; e++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            AL[u].emplace_back(v, w);
        }
        if (BellmanFord(V)) {
            printf("possible\n");
        }
        else {
            printf("not possible\n");
        }
    }

    return 0;
}

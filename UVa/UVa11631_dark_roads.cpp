#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<vii> AL;
vi taken;
priority_queue<ii, vii, greater<ii>> pq;

void process(int u) {
    taken[u] = 1;
    for (auto p : AL[u]) {
        // first is v, second is weight
        if (!taken[p.first]) {
            pq.emplace(p.second, p.first);
        }
    }
}

int main() {
    while (1) {
        int V, E;
        scanf("%d %d", &V, &E);
        if (V == 0 && E == 0)
            break;
        
        int totalCost = 0;
        AL.assign(V, vii());
        taken.assign(V, 0);     // 0 == not taken
        for (int i = 0; i < E; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            AL[u].emplace_back(v, w);
            AL[v].emplace_back(u, w);
            totalCost += w;
        }

        while (!pq.empty()) pq.pop();

        // Prim's algorithm
        process(0);
        int mstCost = 0;
        int numTaken = 0;   // edges taken
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            if (taken[p.second])
                continue;
            mstCost += p.first;
            process(p.second);
            numTaken++;
            if (numTaken == V - 1)
                break;
        }

        printf("%d\n", totalCost - mstCost);
    }
    return 0;
}



#include <bits/stdc++.h>
using namespace std;

typedef unsigned int u32;
typedef vector<u32> vi;

#define INF 1e9

vector<vi> AL;

u32 bfs(u32 start, u32 ttl, u32 V) {
    u32 reached = 1; // start node is counted first
    queue<u32> q;
    vi dist;

    dist.assign(V, INF);
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        u32 u = q.front(); q.pop();
        for (auto v : AL[u]) {
            // we assume ttl value is at least 1
            if (dist[v] == INF) { // new node found
                reached++;
                dist[v] = dist[u] + 1;
                if (dist[v] < ttl) {
                    q.push(v);
                }
            }
        }
    }

    return V - reached; // returns unreachable node count
}

int main() {
    int tc = 1;
    while (1) {
        int nc;
        scanf("%d", &nc);
        if (nc == 0) break;
        AL.assign(100, vi());
        // a map from node label (+ve int) to node indexx (0 to V-1)
        unordered_map<u32, u32> label2Index;
        // assign vertex index to new node as they show up in input
        u32 index = 0; // 0-based indexing
        for (int i = 0; i < nc; i++) {
            u32 u, v;
            scanf("%u %u", &u, &v);
            if (label2Index.count(u) == 0) {
                label2Index.emplace(u, index);
                index++;
            }
            if (label2Index.count(v) == 0) {
                label2Index.emplace(v, index);
                index++;
            }
            AL[label2Index[u]].push_back(label2Index[v]);
            AL[label2Index[v]].push_back(label2Index[u]);
        }
        //u32 V = index; // index is the number of vertex in graph
        while (1) {
            u32 start, ttl;
            scanf("%u %u", &start, &ttl);
            if (start == 0 && ttl == 0)
                break;
            if (label2Index.count(start) == 0) {
                printf("Case %d: %u nodes not reachable from node %u with TTL = %u.\n",
                       tc, index, start, ttl);
            }
            else if (ttl == 0) {
                printf("Case %d: %u nodes not reachable from node %u with TTL = %u.\n",
                       tc, index - 1, start, ttl);
            }
            else {
                u32 s = label2Index[start];
                printf("Case %d: %u nodes not reachable from node %u with TTL = %u.\n",
                        tc, bfs(s, ttl, index), start, ttl);
            }
            tc++;
        }
    }
    return 0;
}

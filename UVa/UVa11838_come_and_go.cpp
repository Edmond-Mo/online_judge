#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vector<vi> AL;
int dfsNumCtr, numSCC;
vi dfsNum, dfsLow, visited;
stack<int> gStk;

void tarjanSCC(int u) {
    dfsNum[u] = dfsLow[u] = dfsNumCtr++;
    gStk.push(u);
    visited[u] = 1;
    for (auto &v : AL[u]) {
        if (dfsNum[v] == -1) {  // unvisited
            tarjanSCC(v);
        }
        if (visited[v]) {
            dfsLow[u] = min(dfsLow[u], dfsLow[v]);
        }
    }

    if (dfsLow[u] == dfsNum[u]) {
        numSCC++;
        while (1) {
            int v = gStk.top();
            gStk.pop();
            visited[v] = 0;
            if (v == u)
                break;
        }
    }
}

int main() {
    int V, E;
    while (1) {
        scanf("%d %d", &V, &E);
        if (V == 0 && E == 0)
            break;
        AL.assign(V, vi());
        int u, v, p;
        for (int i = 0; i < E; i++) {
            scanf("%d %d %d", &u, &v, &p);
            u--; v--;
            AL[u].push_back(v);
            if (p == 2)
                AL[v].push_back(u);
        }

        dfsNum.assign(V, -1);
        dfsLow.assign(V, 0);
        visited.assign(V, 0);
        while (!gStk.empty())
            gStk.pop();
        dfsNumCtr = numSCC = 0;
        for (int i = 0; i < V; i++) {
            if (dfsNum[i] == -1) {  // unvisited
                tarjanSCC(i);
            }
        }

        printf("%d\n", numSCC == 1 ? 1 : 0);
    }
    return 0;
}

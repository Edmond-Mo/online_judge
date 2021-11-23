#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int main() {
    while (1) {
        int V;
        scanf("%d", &V);
        if (V == 0) break;

        int E;
        scanf("%d", &E);
        vector<vi> AL(V, vi());
        for (int i = 0; i < E; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
            AL[u].push_back(v);
            AL[v].push_back(u);
        }

        queue<int> q;
        int s = 0; // starting vertex
        q.push(s);
        vi color(V, -1);
        color[s] = 0;   // color is -1(uncolored), 0, or 1
        bool isBip = true;
        while (!q.empty() && isBip) {
            int u = q.front(); q.pop();
            for (auto &v : AL[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if (color[v] == color[u]) {
                    isBip = false;
                    break;
                }
            }
        }

        printf("%sBICOLORABLE.\n", (isBip ? "" : "NOT "));
    }

    return 0;
}


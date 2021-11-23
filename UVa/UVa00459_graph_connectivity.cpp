#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
int visited[27];
vector<vi> AL;
int numCC;

void dfs_cc(int u) {
    visited[u] = 1;
    for (auto &v : AL[u]) {
        if (!visited[v]) {
            dfs_cc(v);
        }
    }
}

int main() {
    int tc;
    char tmp;
    scanf("%d%c", &tc, &tmp);
    char line[10];
    fgets(line, 10, stdin); // first blank line
    while (tc--) {
        fgets(line, 10, stdin); // max node
        int V = line[0] - 'A' + 1;

        AL.assign(V, vi()); // init for each test case
        numCC = 0;
        memset(visited, 0, sizeof visited);
        while (1) {
            if (fgets(line, 10, stdin) == NULL || strcmp(line, "\n") == 0)
                break;
            auto u = line[0] - 'A';
            auto v = line[1] - 'A';
            AL[u].push_back(v);
            AL[v].push_back(u);
        }

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs_cc(i);
                numCC++;
            }
        }
        printf("%d\n", numCC);
        if (tc) printf("\n");
    }
    return 0;
}







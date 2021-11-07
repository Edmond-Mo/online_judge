#include <bits/stdc++.h>
using namespace std;

typedef unsigned int ui;
typedef vector<ui> vi;
typedef vector<vi> vvi;

/* 
DFS_backtrack(u, path, f)
    if u == f
        path.append(u)
        print (path)
        return
    visited[u] = 1
    path.append(u)
    for v : adjList[u]
        if not visited[v]
            DFS_backtrack(v, path, f)
    visited[u] = 0
    path.pop()

DFS_backtrack(1, [], fire);
*/

ui route;
vi visited(22, 0);
vvi adjList;

void dfs(ui u) {
    visited[u] = 1;
    for (auto v : adjList[u]) {
        if (visited[v])
            continue;
        dfs(v);
    }
}

void dfs_backtrack(ui u, vi path, ui f) {
    if (u == f) {
        route++;

        for (auto v : path) {
            printf("%u ", v);
        }
        printf("%u\n", f);

        return;
    }

    visited[u] = 1;
    path.push_back(u);
    for (auto v : adjList[u]) {
        if (visited[v])
            continue;
        dfs_backtrack(v, path, f);
    }
    visited[u] = 0;
    path.pop_back();
}

int main() {
    ui f;
    char tmp;
    ui n = 1;

    while (1) {
        if (scanf("%u%c", &f, &tmp) != 2)
            break;
        route = 0;
        adjList.assign(22, vi());
        ui cnt = 0;
        while (1) {
            ui v, u;
            scanf("%u %u%c", &v, &u, &tmp);
            if (v == 0 && u == 0)
                break;
            adjList[v].push_back(u);
            adjList[u].push_back(v);
        }

        visited.assign(22, 0);
        dfs(1);
        if (visited[f] == 0) {
            printf("CASE %u:\n", n++);
            printf("There are %u routes from the firestation to streetcorner %u.\n", route, f);
            continue;
        }

        visited.assign(22, 0);
        for (auto &v : adjList) {   // & is important; otherwise a copy of vector v is obtained.
            sort(v.begin(), v.end());
        }

        vi path;
        printf("CASE %u:\n", n++);
        dfs_backtrack(1, path, f);
        printf("There are %u routes from the firestation to streetcorner %u.\n", route, f);
    }
}
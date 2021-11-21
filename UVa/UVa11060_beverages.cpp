#include <bits/stdc++.h>
using namespace std;

#define LIM 120

typedef vector<int> vi;

int main() {
    char line[LIM];
    int tc = 0;
    while (1) {
        if (fgets(line, LIM, stdin) == NULL)    // eof
            break;

        int V;
        sscanf(line, "%d", &V);

        vector<vi> AL(V, vi());
        unordered_map<string, int> s2v;
        unordered_map<int, string> v2s;
        
        for (int i = 0; i < V; i++) {
            fgets(line, LIM, stdin);
            string temp = string(line);
            temp.pop_back(); // remove newline
            s2v[temp] = i;
            v2s[i] = temp;
        }

        vi inDegree(V, 0);
        int E;
        fgets(line, LIM, stdin);
        sscanf(line, "%d", &E);
        for (int i = 0; i < E; i++) {
            char src[LIM];
            char dst[LIM];
            fgets(line, LIM, stdin);
            sscanf(line, "%s %s", src, dst);
            int u = s2v[string(src)];
            int v = s2v[string(dst)];
            AL[u].push_back(v);
            inDegree[v]++;
        }

        priority_queue<int, vi, greater<int>> pq;
        for (int u = 0; u < V; u++) {
            if (inDegree[u] == 0) {
                pq.push(u);
            }
        }

        printf("Case #%d: Dilbert should drink beverages in this order:", ++tc);

        while (!pq.empty()) {
            int u = pq.top(); pq.pop();
            printf(" %s", v2s[u].c_str());
            for (auto &v : AL[u]) {
                inDegree[v]--;
                if (inDegree[v] > 0)
                    continue;
                pq.push(v);
            }
        }

        printf(".\n\n");
        fgets(line, LIM, stdin);
    }

    return 0;
}


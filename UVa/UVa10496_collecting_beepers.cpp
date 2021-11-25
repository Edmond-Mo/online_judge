#include <bits/stdc++.h>
using namespace std;

#define lsone(n) ((n) & -(n))

#define MAX 11

int memo[MAX][(1 << (MAX-1))];
int dist[MAX][MAX];

int tsp(int u, int mask) {
    if (mask == 0) return dist[u][0];
    int &ans = memo[u][mask];
    if (ans != -1) return ans;

    ans = 1e9;
    int m = mask;   // copy of the original mask
    while (m) {
        int bitv = lsone(m);
        int v = __builtin_ctz(bitv) + 1;
        ans = min(ans, dist[u][v] + tsp(v, mask ^ bitv));
        m -= bitv;
    }
    return ans;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int _a, _b;     // not used
        scanf("%d %d", &_a, &_b);
        int x[MAX];
        int y[MAX];
        scanf("%d %d", x, y);
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d %d", x + i, y + i);
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
                dist[j][i] = dist[i][j];
            }
        }
        memset(memo, 0xff, sizeof memo); // all -1
        int len = tsp(0, (1<<n)-1);
        printf("The shortest path has length %d\n", len);
    }
    return 0;
}
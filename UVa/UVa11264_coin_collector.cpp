#include <bits/stdc++.h>
using namespace std;

typedef unsigned int u32;

int main() {
    int tc;

    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        int cv[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", cv + i);
        }
        int ans = 1;
        int sum = cv[0];
        for (int i = 1; i < n - 1; i++) {
            if ((sum + cv[i]) < cv[i + 1]) {
                sum += cv[i];
                ans++;
            }
        }
        printf("%d\n", ans + 1);
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        int p[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", p + i);
        }
        sort(p, p + n, greater<int>());

        int discount = 0;
        for (int i = 0; i < n; i += 3) {
            if ((i + 2) < n)
                discount += p[i + 2];
        }
        printf("%d\n", discount);
    }
}
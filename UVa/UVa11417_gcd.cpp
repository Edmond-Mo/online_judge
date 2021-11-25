#include <bits/stdc++.h>
using namespace std;

unsigned int memo[510][510] = {0};

inline unsigned int gcd(unsigned int a, unsigned int b) {
    if (b == 0) return a;
    if (memo[a][b]) return memo[a][b];
    memo[a][b] = gcd(b, a % b);
    return memo[a][b];
}

int main() {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        unsigned int g = 0;
        for (unsigned int i = 1; i < n; i++) {
            for (unsigned int j = i + 1; j <= n; j++) {
                g += gcd(i, j);
            }
        }
        printf("%u\n", g);
    }
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <algorithm>

#define LIM 1000020
typedef unsigned long long u64;

u64 T[LIM];

int main() {
    u64 adj = 0;
    T[3] = 0;
    for (int i = 4; i < LIM; i++) {
        adj += (i - 2) / 2;
        T[i] = T[i-1] + adj;
    }
    int n;
    while (1) {
        scanf("%d", &n);
        if (n < 3) break;
        printf("%llu\n", T[n]);
    }
    return 0;
}

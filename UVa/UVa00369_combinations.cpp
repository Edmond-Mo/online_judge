#include <cstdio>
#include <cstdlib>

#define LIM 108

// pt[n][k]: n Choose k
// Pascal's Triangle
unsigned int pt[LIM][LIM];

inline static void gen() {
    // Pascal's rule:
    // base case:
    // n C 0 == n C n == 1
    // recurrence:
    // n C k + n C k+1 = n+1 C k+1
    int n = 100;
    int k = 100;
    for (int i = 0; i <= n; i++) {
        pt[i][0] = pt[i][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            pt[i][j] = pt[i-1][j-1] + pt[i-1][j];
        }
    }
}

int main() {
    gen();
    while (1) {
        int n, k;
        scanf("%d %d", &n, &k);
        if (n == 0 && k == 0)
            break;
        printf("%d things taken %d at a time is %u exactly.\n", n, k, pt[n][k]);
    }
    return 0;
}

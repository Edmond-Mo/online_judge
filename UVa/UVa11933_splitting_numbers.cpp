#include <bits/stdc++.h>

int main() {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        int i = 0;
        int a = 0;
        int counter = 1;
        while (i < 32) {
            int mask = 1 << i;
            if (n & mask) {
                if (counter & 1)
                    a += mask;
                counter++;
            }
            i++;
        }
        printf("%d %d\n", a, n - a);
    }
    return 0;
}
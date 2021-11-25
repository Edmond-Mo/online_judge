#include <bits/stdc++.h>
using namespace std;

unsigned char num[100030];

int main() {
    int tc;
    int N, Q;
    int temp;
    int real_N;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d %d", &N, &Q);
        real_N = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &temp);
            temp &= 0xff;
            if (temp) {
                num[real_N++] = (unsigned char)temp;
            }
        }
        int a;
        for (int q = 0; q < Q; q++) {
            unsigned char best = 0;
            unsigned char curr;
            scanf("%d", &a);
            if (a == 0) {
                printf("0\n");
                continue;
            }
            for (int i = 0; i < real_N; i++) {
                curr = num[i] & (unsigned char)a;
                if (curr == (unsigned char)a) {
                    best = curr;
                    break;
                }
                if (curr > best) {
                    best = curr;
                }
            }
            printf("%d\n", best);
        }
    }
    return 0;
}
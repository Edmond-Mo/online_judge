#include <bits/stdc++.h>
using namespace std;

int id[10010] = {0};

int main() {
    int N, R;
    int temp;
    while (scanf("%d %d", &N, &R) != EOF) {
        memset(id, 0, sizeof(int) * (N+1));
        for (int i = 0; i < R; i++) {
            scanf("%d", &temp);
            id[temp] = 1;
        }
        if (N == R) {
            printf("*\n");
            continue;
        }

        int r = 1;
        for (int i = 1; i <= N && r <= (N - R); i++) {
            if (id[i] == 0) {
                printf("%d ", i);
                r++;
            }
        }
        printf("\n");
    }

    return 0;
}
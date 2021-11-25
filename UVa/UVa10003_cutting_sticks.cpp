#include <bits/stdc++.h>
using namespace std;

int cuts[1010][1010];
int main() {

    while (1) {
        int len;
        scanf("%d", &len);
        if (len == 0) break;
        int n;
        scanf("%d", &n);
        n += 2;
        int ofst[n];
        ofst[0] = 0;
        ofst[n-1] = len;
        for (int i = 1; i <= (n-2); i++) {
            scanf("%d", ofst + i);
        }
        memset(cuts, 0, sizeof cuts);
        for (int i = 0; i < n - 1; i++) {
            cuts[i][i+1] = 0;   // no more cuts
            if (i < n - 2) {
                cuts[i][i+2] = ofst[i+2] - ofst[i];  // only one way to cut
            }
        }

        // build from increasingly longer segments of sticks
        for (int s = 3; s < n; s++) {
            for (int i = 0; i < (n - s); i++) {
                int minCost = 1e9;
                for (int pt = i + 1; pt < i + s; pt++) {
                    int curr = cuts[i][pt] + cuts[pt][i+s] + ofst[s+i] - ofst[i];
                    if (curr < minCost)
                        minCost = curr;
                }
                cuts[i][i+s] = minCost;
            }
        }

        printf("The minimum cutting is %d.\n", cuts[0][n-1]);
    }

    return 0;
}
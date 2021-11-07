#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<float, int>> vp;

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        int days[n];
        int fines[n];
        vp ratio;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", days + i, fines + i);
            ratio.emplace_back((float)days[i]/fines[i], i);
        }
        sort(ratio.begin(), ratio.end());

        for (int i = 0; i < n; i++) {
            if (i > 0)
                printf(" ");
            printf("%d", ratio[i].second + 1);
        }
        printf("\n");
        if (tc)
            printf("\n");
    }
}
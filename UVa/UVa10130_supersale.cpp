#include <bits/stdc++.h>
using namespace std;

#define MAX_OBJ 1008
int objs;
int price[MAX_OBJ];
int weight[MAX_OBJ];
int memo[MAX_OBJ][32];

int dp(int obj, int remainWeight) {
    // base case
    // why remWeight == 0 but not <= 0? because we won't
    // recurse down if the remainWeight is less than the weight
    // of the current obj
    if (obj == objs || remainWeight == 0)
        return 0;
    int &ans = memo[obj][remainWeight];
    if (ans != -1)
        return ans;
    if (weight[obj] > remainWeight) {
        // skip the current obj
        ans = dp(obj + 1, remainWeight);
        return ans;
    }

    ans = max(dp(obj + 1, remainWeight),
              price[obj] + dp(obj + 1, remainWeight - weight[obj]));
    return ans;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &objs);
        for (int i = 0; i < objs; i++) {
            scanf("%d %d", price + i, weight + i);
        }
        int grp;
        scanf("%d", &grp);
        int maxValue = 0;
        for (int i = 0; i < grp; i++) {
            int remainWeight;
            scanf("%d", &remainWeight);
            // all 0xff bytes ==> memo[i][j] = -1 (2's complement reason)
            memset(memo, char(0xff), sizeof memo);
            maxValue += dp(0, remainWeight);
        }
        printf("%d\n", maxValue);
    }
    return 0;
}


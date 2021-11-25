#include <bits/stdc++.h>
using namespace std;

/*
ways(i, rem): total ways to make changes for rem when considering coin value i
C: number of coin values
base case:
    i == C: no more coin type to choose, return 0
    rem == 0: found a new way to make change, return 1
    rem < 0: return 0
recurrence:
    ways(i, rem) = ways(i, rem - cv[i]) +    // use current coin type
                   ways(i + 1, rem)          // pass current coin type
*/

int cv[5] = {50, 25, 10, 5, 1};
int memo[6][7500];

int ways(int i, int rem) {
    if (i == 5) return 0;
    if (rem == 0) return 1;
    if (rem < 0) return 0;

    int& ans = memo[i][rem];
    if (ans != -1) return ans;

    ans = ways(i, rem - cv[i]) + ways(i + 1, rem);
    return ans;
}

int main() {
    int value;
    memset(memo, 0xff, sizeof memo);
    while (scanf("%d", &value) != EOF) {
        printf("%d\n", ways(0, value));
    }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;
        priority_queue<int, vector<int>, greater<int> > num;
        for (int i = 0; i < n; i++) {
            int k;
            scanf("%d", &k);
            num.push(k);
        }
        int cost = 0;
        for (int i = 0; i < (n - 1); i++) {
            int one = num.top(); num.pop();
            int two = num.top(); num.pop();
            int total = one + two;
            num.push(total);
            cost += total;
        }

        printf("%d\n", cost);
    }
    return 0;
}
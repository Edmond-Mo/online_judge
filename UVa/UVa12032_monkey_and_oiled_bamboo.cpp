#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int cando(int k, vi &arr, int n) {
    for (int i = 1; i <= n; i++) {
        int jump = arr[i] - arr[i-1];
        if (jump == k) {
            k--;
        }
        else if (jump > k) {
            return 0; // can't reach the top
        }
    }

    return 1;
}

int bsta(vi &arr, int n) {
    int low = 1;
    int high = arr[n] * 3;

    int mid;
    for (int i = 0; i < 30; i++) {
        mid = low + (high - low) / 2;
        if (cando(mid, arr, n)) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }

    return mid;
}

int main()
{
    int tc;
    char tmp;

    scanf("%d%c", &tc, &tmp);
    for (int c = 1; c <= tc; c++) {
        int n;
        vi arr;
        scanf("%d%c", &n, &tmp);
        arr.assign(n + 1, 0);
        arr[0] = 0;  // floor
        for (int i = 1; i <= n; i++) {
            int t;
            scanf("%d", &t);
            arr[i] = t;
        }
        int k = bsta(arr, n);
        printf("Case %d: %d\n", c, k);
    }
    return 0;
}
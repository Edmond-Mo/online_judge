#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

void findsum(vi &arr, int len, int total)
{
    int bestL = 1e9;
    int bestR = 0;

    int L = 0;
    int R = len - 1;

    while (L < R) {
        if (arr[L] + arr[R] == total) {
            if (abs(arr[L] - arr[R]) < abs(bestL - bestR)) {
                bestL = arr[L];
                bestR = arr[R];
            }
            L++;
            R--;
        }
        else if (arr[L] + arr[R] > total) {
            R--;
        }
        else {
            L++;
        }
    }

    printf("Peter should buy books whose prices are %d and %d.\n\n", bestL, bestR);

}

int main() {
    while (1) {
        int N, total;
        vi arr;
        char tmp;
        char buf[16];

        if (scanf("%d%c", &N, &tmp) == EOF) {
            break;
        }
        for (int i = 0; i < N; i++) {
            int t;
            scanf("%d", &t);
            arr.push_back(t);
        }
        scanf("%c", &tmp);
        scanf("%d%c", &total, &tmp);
        fgets(buf, 16, stdin);

        sort(arr.begin(), arr.end());
        findsum(arr, N, total);
    }
    return 0;
}
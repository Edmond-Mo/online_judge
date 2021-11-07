#include <bits/stdc++.h>
using namespace std;

int main()
{
    while (1) {
        int n;
        scanf("%d", &n);
        if (n == 0)
            break;
        int num[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", num + i);
        }

        int prevSum = 0;
        int maxSum = -1e9;
        for (int i = 0; i < n; i++) {
            int newSum = prevSum + num[i];
            if (newSum > 0) {
                if (num[i] > newSum)
                    newSum = num[i];
                prevSum = newSum;
            }
            else {
                prevSum = 0;
            }

            maxSum = max(maxSum, newSum);
        }

        if (maxSum <= 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n", maxSum);
    }

    return 0;
}

    

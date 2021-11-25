#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ull;
int main()
{
    int tc;
    ull n;
    scanf("%d", &tc);
    while (tc--)
    {
        scanf("%llu", &n);

        ull low = 0;  // these are row numbers
        ull high = n; // n rows worth of worriors >= n warriors
        ull mid = 0;

        if (high > 0xFFFFFFFF)
            high = 0xFFFFFFFF;

        while (low <= high)
        {
            mid = low + (high - low) / 2;
            ull sum = mid * (mid + 1) / 2;
            if (sum == n) { // mid is exact rows of warriors
                break;
            }
            else if (sum < n) {
                low = mid + 1;
            }
            else if (sum > n) {
                if (mid > 0) {
                    ull prev_sum = (mid - 1) * mid / 2;
                    if (prev_sum <= n) {
                        mid--; // ans is mid - 1
                        break;
                    }
                }
                high = mid - 1;
            }
        }

        printf("%llu\n", mid);
    }

    return 0;
}
#include <cstdio>
#include <algorithm>

int main() {
    int N, M;
    while(1) {
        scanf("%d %d", &N, &M);
        printf("%d %d\n", N, M);
        if (N == 0 && M == 0)
            break;
        int nums[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", nums + i);
        }
        std::sort(nums, nums + N,
            [M](int& a, int& b)
            {
                int ma = a % M;
                int mb = b % M;
                if (ma < mb)
                    return true;
                if (ma == mb) {
                    int ba = a & 1;
                    int bb = b & 1;
                    if ((ba == 1) && (bb == 0)) {
                        return true;
                    }

                    if ((ba == 1) && (bb == 1)) {
                        if (a > b) {
                            return true;
                        }

                    }
                    if ((ba == 0) && (bb == 0)) {
                        if (a < b) {
                            return true;
                        }
                    }
                }

                return false;
            });

        for (int i = 0; i < N; i++) {
            printf("%d\n", nums[i]);
        }
    }

    return 0;
}

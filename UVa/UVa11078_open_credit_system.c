#include <stdio.h>

int score[1000010];

int main()
{
    int i, tc, n, max_score, best, delta;
    scanf("%d", &tc);
    while (tc--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++) {
            scanf("%d", score + i);
        }
        best = -1000000;
        max_score = score[0];
        for (i = 1; i < n; i++) {
            delta = max_score - score[i];
            if (delta > best) {
                best = delta;
            }
            if (score[i] > max_score) {
                max_score = score[i];
            }
        }
        printf("%d\n", best);
    }
    return 0;
}
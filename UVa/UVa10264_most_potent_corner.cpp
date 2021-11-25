#include <bits/stdc++.h>
#include <string.h>
using namespace std;

int weight[16390];
int potent[16390];

int main() {
        int N;
        while (1) {
                if (scanf("%d", &N) == EOF)
                        break;
                int num = 1 << N;
                memset(weight, 0, sizeof(int) * num);
                memset(potent, 0, sizeof(int) * num);
                for (int i = 0; i < num; i++) {
                        scanf("%d", weight + i);
                }
                // calc potency for each corner
                for (int i = 0; i < num; i++) {
                        int mask = 1;
                        // toggle each bit to get neighbor's id
                        for (int b = 0; b < N; b++) {
                                potent[i] += weight[i ^ mask];
                                mask = mask << 1;
                        }
                }
                int max_p = 0;
                for (int i = 0; i < num; i++) {
                        int mask = 1;
                        for (int b = 0; b < N; b++) {
                                int sum = potent[i] + potent[i ^ mask];
                                if (sum > max_p)
                                        max_p = sum;
                                mask = mask << 1;
                        }
                }
                printf("%d\n", max_p);
        }

        return 0;
}

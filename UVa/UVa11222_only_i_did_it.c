#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int score[10240];
int score_list[3][10240];

int main()
{
    int tc;
    int sizes[3];
    char c;
    int temp;
    int winners[3];
    int unique[3];
    int best_unique;
    int casenum = 1;

    scanf("%d%c", &tc, &c);

    while (casenum <= tc) {
        memset((void*)score, 0, sizeof(int) * 10240);
        memset((void*)score_list[0], 0, sizeof(int) * 10240);
        memset((void*)score_list[1], 0, sizeof(int) * 10240);
        memset((void*)score_list[2], 0, sizeof(int) * 10240);
        winners[0] = winners[1] = winners[2] = 0;
        unique[0] = unique[1] = unique[2] = 0;
        for (int player = 0; player < 3; player++) {
            scanf("%d", &sizes[player]);
            for (int i = 0; i < sizes[player]; i++) {
                scanf("%d", &temp);
                score_list[player][temp]++; 
            }
        }

        for (int s = 0; s < 10240; s++) {
            int cnt = 0;
            int player_who_solve_this_problem = 0;
            for (int p = 0; p < 3; p++) {
                if (score_list[p][s]) {
                    cnt++;
                    player_who_solve_this_problem = p;
                    score_list[p][s] = 0; 
                } 
            }
            if (cnt == 1) { // only one player solve this problem
                unique[player_who_solve_this_problem]++;
                score_list[player_who_solve_this_problem][s] = 1;
            }
        }

        best_unique = -1;
        for (int player = 0; player < 3; player++) {
            if (unique[player] > best_unique)
                best_unique = unique[player];
        }

        int numWinner = 0;
        for (int player = 0; player < 3; player++) {
            if (unique[player] == best_unique) {
                winners[player] = 1;
                numWinner++;
            }
        }

        int winner_count = 0;
        printf("Case #%d:\n", casenum);
        for (int i = 0; i < 3; i++) {
            if (winners[i]) {
                printf("%d %d", i + 1, unique[i]);
                for (int s = 0; s < 10240; s++) {
                    if (score_list[i][s]) {
                        printf(" %d", s);
                    }
                }
                winner_count++;

                if (casenum == tc) {
                    if (winner_count != numWinner)
                        printf("\n");
                }
                else
                    printf("\n");
            }
        }

        casenum++;
    }

    printf("\n");
    return 0;
}
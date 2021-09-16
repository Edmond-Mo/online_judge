#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 30
char code[55][MAX_LINE];
int len[55];
int arrange[55];

int main()
{
    int N;
    int i;
    char c;
    while (1) {
        scanf("%d%c", &N, &c); // scan the \n char. otherwise the fgets below will get a blank line
        if (N == 0) {
            break;
        }
        memset((void*)arrange, -1, sizeof(int) * 55);
        for (i = 0; i < N; i++) {
            fgets(code[i], MAX_LINE, stdin);
            // each line has pattern "CC VARNAME\n"
            // so length of VARNAME is strlen() - 4
            len[i] = strlen(code[i]) - 4;
            // fill the space in the pattern with '\0' to make
            // it the code name itself
            code[i][2] = '\0';
        }

        // i is used to walk around the arrangement array
        i = 0;
        // for each card, look for starting pos
        for (int card = 0; card < N; card++) {
            int count = 0;
            while (1) {
                if (arrange[i] == -1) { // unused slot
                    count++;
                    if (count == len[card]) {
                        arrange[i] = card;
                        break;
                    }
                }
                i++;
                if (i >= N)
                    i = 0;     // cycle
            }
        }

        for (int card = 0; card < N; card++) {
            if (card == (N - 1)) {
                printf("%s\n", code[arrange[card]]);
            }
            else {
                printf("%s ", code[arrange[card]]);
            }
        }
    }
    return 0;
}

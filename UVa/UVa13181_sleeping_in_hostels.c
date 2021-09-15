#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
    LEFT_WALL,
    MIDDLE,
};

char line[500020];

int main()
{
    int len;
    int i;
    int max;
    int left_dot;
    int right_dot;
    int mid_dot;
    int state;
    int ans;

    while (scanf("%s", line) != EOF) {
        len = strlen(line);
        max = 0;
        left_dot = 0;
        right_dot = 0;
        mid_dot = 0;
        state = LEFT_WALL;

        for (i = 0; i < len; i++) {
            if (line[i] == 'X') {
                mid_dot = 0;
                if (state == LEFT_WALL) {
                    state = MIDDLE;
                }
            }
            else if (line[i] == '.') {
                switch (state) {
                    case LEFT_WALL:
                        left_dot++;
                        break;

                    case MIDDLE:
                        mid_dot++;
                        break;
                }
                
                if (mid_dot > max) {
                    max = mid_dot;
                }

                if (i == (len - 1)) {
                    right_dot = mid_dot;
                }
            }
        }

        // put max wall dots to left_dot
        if (left_dot < right_dot)
            left_dot = right_dot;
        ans = (max - 1) / 2;
        if (ans < (left_dot - 1))
            ans = left_dot - 1;

        printf("%d\n", ans);

    }
    return 0;
}


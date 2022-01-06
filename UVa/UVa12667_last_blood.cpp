#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
    int prob, team, sub;
    scanf("%d %d %d", &prob, &team, &sub);
    int accepted[16][128] = {0};
    int lastBlood[16][2] = {0};
    for (int i = 0; i < sub; i++) {
        int ts;
        int m;
        char p;
        char yes[5];
        scanf("%d %d %c %s", &ts, &m, &p, yes);
        if (strcmp(yes, "Yes"))
            continue;
        if (!accepted[p - 'A'][m]) {
            accepted[p - 'A'][m] = 1;
            lastBlood[p - 'A'][0] = m;
            lastBlood[p - 'A'][1] = ts;
        }
    }

    for (int p = 0; p < prob; p++) {
        if (lastBlood[p][0]) {
            printf("%c %d %d\n", (char)(p + 'A'), lastBlood[p][1], lastBlood[p][0]);
        }
        else {
            printf("%c - -\n", (char)(p + 'A'));
        }
    }
    return 0;
}


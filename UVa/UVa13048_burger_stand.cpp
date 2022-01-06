#include <cstdio>
#include <cstring>

int main() {
    int N;
    char tmp;
    scanf("%d%c", &N, &tmp);
    int tc = 1;
    char line[55];
    while (tc <= N) {
        fgets(line, 55, stdin);
        int len = strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = '\0';
            len--;
        }
        char shadow[len] = {0};
        for (int i = 0; i < len; i++) {
            if (line[i] == 'B') {
                shadow[i] = 1; // 1 means no good
                if (i > 0)
                    shadow[i-1] = 1;
                if (i > 1)
                    shadow[i-2] = 1;
            }
            else if (line[i] == 'D') {
                shadow[i] = 1;
            }
            else if (line[i] == 'S') {
                shadow[i] = 1;
                if (i > 0)
                    shadow[i-1] = 1;
                if (i < len - 1)
                    shadow[i+1] = 1;
            }
        }

        int good_spots = 0;
        for (int i = 0; i < len; i++) {
            if (line[i] == '-' && shadow[i] == 0)
                good_spots++;
        }

        printf("Case %d: %d\n", tc, good_spots);
        tc++;
    }

    return 0;
}

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

typedef unsigned int u32;

inline int getIndex(u32 fib)
{
    if (fib == 1)
        return 0;
    if (fib == 2)
        return 1;
    int index = 2;
    u32 a = 1;
    u32 b = 2;
    u32 next = 3;
    while (next != fib) {
        a = b;
        b = next;
        next = a + b;
        index++;
    }

    //printf("%d -> %d\n", fib, index);
    return index;
}

int main() {
    int tc;
    scanf("%d", &tc);
    while (tc--) {
        int n;
        scanf("%d", &n);
        u32 fs[n];
        for (int i = 0; i < n; i++)
            scanf("%u", fs + i);
        char tmp;
        scanf("%c", &tmp);
        char line[108];
        fgets(line, 108, stdin);
        char decoded[108];
        for (int i = 0; i < 108; i++)
            decoded[i] = ' ';
        int k = 0;
        int m = 0;
        int len = strlen(line);
        int maxIndex = 0;
        while (k < len && m < n) {
            if (line[k] >= 'A' && line[k] <= 'Z') {
                int idx = getIndex(fs[m]);
                decoded[idx] = line[k];
                m++;
                if (idx > maxIndex)
                    maxIndex = idx;
            }
            k++;
        }

        decoded[maxIndex+1] = '\0';
        printf("%s\n", decoded);
    }
    return 0;
}


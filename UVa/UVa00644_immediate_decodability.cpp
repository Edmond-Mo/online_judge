#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define SZ 12
#define GP 10

// return true if a is a prefix of b
inline bool isPrefix(char *a, int m, char *b)
{
    int i = 0;
    bool pre = true;
    while (i < m) {
        if (a[i] != b[i])
        {
            pre = false;
            break;
        }
        i++;
    }

    return pre;
}

int main() {
    char codes[GP][SZ];
    int n = 0;
    bool immed;
    int s = 1;
    while (1) {
        if (fgets(codes[n], SZ, stdin) == NULL || strcmp(codes[n], "\n") == 0)
            break;
        if (codes[n][strlen(codes[n])-1] == '\n')
            codes[n][strlen(codes[n])-1] = '\0';
        if (codes[n][0] == '9') {
            immed = true;
            for (int i = 0; i < n && immed; i++) {
                for (int j = 0; j < n; j++) {
                    int m = strlen(codes[i]);
                    int n = strlen(codes[j]); 
                    if (i == j || m > n)
                        continue;
                    if (isPrefix(codes[i], m, codes[j])) {
                        immed = false;
                        break;
                    }
                }
            }
            if (immed) {
                printf("Set %d is immediately decodable\n", s);
            }
            else {
                printf("Set %d is not immediately decodable\n", s);
            }
            s++;
            n = 0;
        }
        else {
            n++;
        }
    }
    return 0;
}


#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    char s[n][4];
    for (int i = 0; i < n; i++) {
        scanf("%s", s + i);
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        int pos;
        scanf("%d", &pos);
        pos--;
        if (s[pos][0] != '?') {
            printf("%s\n", s[pos]);
            continue;
        }
        int left_index = 0;
        int right_index = 0;
        bool found_left = false;
        bool found_right = false;
        for (int k = pos - 1; k >= 0; k--) {
            if (s[k][0] != '?') {
                found_left = true;
                left_index = k;
                break;
            }
        }
        for (int k = pos + 1; k < n; k++) {
            if (s[k][0] != '?') {
                found_right = true;
                right_index = k;
                break;
            }
        }
        if (found_left && found_right) {
            if (pos - left_index == right_index - pos) {
                printf("middle of %s and %s\n", s[left_index], s[right_index]);
            }
            else if (pos - left_index < right_index - pos) {
                int d = pos - left_index;
                for (int j = 0; j < d; j++)
                    printf("right of ");
                printf("%s\n", s[left_index]);
            }
            else {
                int d = right_index - pos;
                for (int j = 0; j < d; j++)
                    printf("left of ");
                printf("%s\n", s[right_index]);
            }
        }
        else if (found_left) {
            int d = pos - left_index;
            for (int j = 0; j < d; j++)
                printf("right of ");
            printf("%s\n", s[left_index]);
        }
        else {
            int d = right_index - pos;
            for (int j = 0; j < d; j++)
                printf("left of ");
            printf("%s\n", s[right_index]);
        }
    }
    return 0;
}
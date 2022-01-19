#include <cstdio>
#include <algorithm>

enum {
    PLUS = 0,
    MINUS = 1,
    PROD = 2,
};

bool backtrack(int *a, int i, int op, int intermed) {
    if (i == 5) {
        if (intermed == 23)
            return true;
        return false;
    }

    switch (op) {
        case PLUS:
            intermed = intermed + a[i];
            break;
        case MINUS:
            intermed = intermed - a[i];
            break;
        case PROD:
            intermed = intermed * a[i];
            break;
    }

    return backtrack(a, i + 1, 0, intermed) ||
           backtrack(a, i + 1, 1, intermed) ||
           backtrack(a, i + 1, 2, intermed);
}

int main() {
    int a[5];
    while (1) {
        scanf("%d %d %d %d %d", a, a+1, a+2, a+3, a+4);
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0)
            break;
        std::sort(a, a + 5);
        bool found = false;
        do { 
            if (backtrack(a, 1, 0, a[0]) ||
                backtrack(a, 1, 1, a[0]) ||
                backtrack(a, 1, 2, a[0])) {
                found = true;
                break;
            }
        } while (std::next_permutation(a, a + 5));
        if (found)
            printf("Possible\n");
        else
            printf("Impossible\n");
    }

    return 0;
}
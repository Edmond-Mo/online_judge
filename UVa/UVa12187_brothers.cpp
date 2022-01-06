#include <cstdio>
#include <cstring>

#define WIDTH 100

struct Cell {
    int owner;
    int attackedBy;
};

// return true if a hates b
// if a is N - 1 and b is 0, yes
// else if b - a = 1, yes
// else, no
inline bool doHate(int a, int b, int N) {
    if (a == N - 1) {
        if (b == 0)
            return true;
        return false;
    }

    if (b - a == 1)
        return true;

    return false;
}

inline void attackRound(Cell field[][WIDTH], int R, int C, int N) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            // attck top
            if (i > 0 && doHate(field[i][j].owner, field[i-1][j].owner, N))
                field[i-1][j].attackedBy = field[i][j].owner;
            // attack bottom
            if (i < R - 1 && doHate(field[i][j].owner, field[i+1][j].owner, N))
                field[i + 1][j].attackedBy = field[i][j].owner;
            // attack left
            if (j > 0 && doHate(field[i][j].owner, field[i][j-1].owner, N))
                field[i][j-1].attackedBy = field[i][j].owner;
            // attack right
            if (j < C - 1 && doHate(field[i][j].owner, field[i][j+1].owner, N))
                field[i][j+1].attackedBy = field[i][j].owner;
        }
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (field[i][j].attackedBy != -1) {
                field[i][j].owner = field[i][j].attackedBy;
                field[i][j].attackedBy = -1;
            }
        }
    }
}


int main() {
    int N, R, C, B;
    while (1) {
        scanf("%d %d %d %d", &N, &R, &C, &B);
        if (N == 0 && R == 0 && C == 0 && B == 0) {
            break;
        }

        Cell field[R][WIDTH];
        memset(field, 0xff, sizeof field); // make all -1
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                scanf("%d", &(field[r][c].owner));
            }
        }

        for (int battle = 0; battle < B; battle++) {
            attackRound(field, R, C, N);
        }

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (c == C - 1)
                    printf("%d", field[r][c].owner);
                else
                    printf("%d ", field[r][c].owner);
            }
            printf("\n");
        }
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isZero(int g[3][3])
{
    int sum = 0;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            sum += g[i][j];
    return sum == 0;
}

void trans(int g[3][3])
{
    int h[3][3];
    memcpy((void*)h, (void*)g, sizeof(int) * 9);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int sum = 0;
            if (i > 0)
                sum += h[i-1][j]; // up
            if (i < 2)
                sum += h[i+1][j]; // down
            if (j > 0)
                sum += h[i][j-1]; // left
            if (j < 2)
                sum += h[i][j+1]; // right
            g[i][j] = sum % 2;
        }
    }
}

int main()
{
    int grid[3][3];
    int tc;
    char c;
    char line[10];
    scanf("%d%c", &tc, &c);

    while (tc--) {
        scanf("%c", &c);
        int sum = 0;
        for (int r = 0; r < 3; r++) {
            fgets(line, 10, stdin);
            for (int c = 0; c < 3; c++) {
                int cell = line[c] - '0';
                grid[r][c] = cell;
                sum += cell; 
            }
        }

        if (sum == 0) {
            printf("-1\n");
        }
        else {
            int n = 0;
            while (!isZero(grid)) {
                n++;
                trans(grid);
            }
            printf("%d\n", n - 1);
        }
    }
    return 0;
}
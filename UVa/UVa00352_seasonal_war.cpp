#include <bits/stdc++.h>
using namespace std;

#define LIM 100

int dr[] = { -1, -1,  0,  1,  1,  1,  0, -1 };
int dc[] = {  0,  1,  1,  1,  0, -1, -1, -1 };

void floodfill(char grid[LIM][LIM], int n, int r, int c, char c1, char c2)
{
    if (r < 0 || r >= n || c < 0 || c >= n)
        return;

    if (grid[r][c] != c1)
        return;

    grid[r][c] = c2;

    for (int i = 0; i < 8; i++) {
        floodfill(grid, n, r+dr[i], c+dc[i], c1, c2);
    }
}

int main() {
    int n;
    char line[LIM];
    int tc = 1;
    while (1) {
        if (fgets(line, LIM, stdin) == NULL || strcmp(line, "\n") == 0)
            break;
        sscanf(line, "%d", &n);
        char grid[LIM][LIM];
        for (int i = 0; i < n; i++) {
            fgets(grid[i], LIM, stdin);
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    floodfill(grid, n, i, j, '1', '0');
                    ans++;
                }
            }
        }

        printf("Image number %d contains %d war eagles.\n", tc++, ans);
    }
    return 0;
}



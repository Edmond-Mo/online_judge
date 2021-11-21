#include <bits/stdc++.h>
using namespace std;

#define LIM 110

char grid[LIM][LIM];
int R, C;
//           S,SE, E,NE, N,NW, W,SW 
int dr[] = { 1, 1, 0,-1,-1,-1, 0, 1};
int dc[] = { 0, 1, 1, 1, 0,-1,-1,-1};

int floodfill(int r, int c, char c1, char c2) {
    if (r < 0 || r >= R || c < 0 || c >= C)
        return 0;
    if (grid[r][c] != c1)
        return 0;
    int ans = 1;
    grid[r][c] = c2;
    for (int i = 0; i < 8; i++) {
        ans += floodfill(r + dr[i], c + dc[i], c1, c2);
    }
    return ans;
}

int main() {
    int tc;
    char tmp; // to dump newline
    scanf("%d%c", &tc, &tmp);
    scanf("%c", &tmp); // remove blank line

    while (tc--) {
       R = 0;
       while (1) {
           fgets(grid[R], LIM, stdin);
           if (grid[R][0] != 'L' && grid[R][0] != 'W')
               break;
           R++;
       } // when break, grid[R] has the first query 

       C = strlen(grid[0]);

       char line[LIM];
       memcpy(line, grid[R], C + 1);
       while (1) {
           int row;
           int col;
           sscanf(line, "%d %d", &row, &col);
           row--; col--;
           printf("%d\n", floodfill(row, col, 'W', '.'));
           floodfill(row, col, '.', 'W');
           if (fgets(line, LIM, stdin) == NULL || strcmp(line, "\n") == 0)
               break;
       }

       if (tc) printf("\n");
    }

    return 0;
}


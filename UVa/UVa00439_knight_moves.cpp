#include <bits/stdc++.h>
using namespace std;

int main() {
    int dr[] = {-2, -1,  1,  2,  2,  1, -1, -2}; // clockwise
    int dc[] = { 1,  2,  2,  1, -1, -2, -2, -1};
    char line[20];
    int grid[8][8];
    while (1) {
        if (fgets(line, 20, stdin) == NULL || strcmp(line, "\n") == 0) {
            break;
        }

        queue<pair<int, int>> q;    // store tuples of (r, c)
        memset(grid, 0xff, sizeof grid); // -1 = unvisited
        
        int c1 = line[0] - 'a';     // start
        int c2 = line[3] - 'a';
        int r1 = line[1] - '1';     // end
        int r2 = line[4] - '1';

        if (c1 == c2 && r1 == r2) {
            printf("To get from %c%c to %c%c takes 0 knight moves.\n",
                line[0], line[1], line[3], line[4]);
            continue;
        }

        // BFS variant
        q.push({r1, c1});
        grid[r1][c1] = 0;   // visited; dist from start is 0 (self)
        bool found = false;
        while (!q.empty() && !found) {
            auto p = q.front(); q.pop();
            for (int i = 0; i < 8; i++) {
                int newR = p.first + dr[i];
                int newC = p.second + dc[i];
                if (newR < 0 || newR >= 8 || newC < 0 || newC >= 8)
                    continue;
                if (grid[newR][newC] == -1) {
                    grid[newR][newC] = grid[p.first][p.second] + 1;
                    if (newR == r2 && newC == c2) {
                        found = true;
                        break;
                    }
                    q.push({newR, newC});
                }
            }
        }

        printf("To get from %c%c to %c%c takes %d knight moves.\n",
               line[0], line[1], line[3], line[4], grid[r2][c2]);
    }
    return 0;
}
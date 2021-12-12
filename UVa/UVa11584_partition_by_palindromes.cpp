#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define LIM 1024
#define INF 1e9

int isp[LIM][LIM];
int mp[LIM][LIM];
char line[LIM];

unsigned long debug01 = 0;
unsigned long debug02 = 0;
unsigned long debug03 = 0;
unsigned long debug04 = 0;

// bottom-up DP approach by building the isp table
inline void solveP(int len)
{
    for (int i = 0; i < len; i++) {
        // even len base case
        isp[i][i] = 1;
        // odd len base case
        if (i < len - 1)
            isp[i][i+1] = line[i] == line[i+1] ? 1 : 0;
    }

    // recurrance: isp(l, r) = s[l] == s[r] and isp(l+1, r-1)
    // picture a table where we only care about the top right
    // portion and where each cell depends on the cell value
    // of the lower left cell.

    // fill table by increasingly longer substr
    for (int sub = 2; sub <= len; sub++) {
        for (int l = 0; l < len; l++) {
            int r = l + sub;
            if (r >= len) continue;
            if (line[l] != line[r])  
                isp[l][r] = 0;
            else
                isp[l][r] = isp[l+1][r-1];
        }
    }
}

// recursive top-down DP with memo
// mp(l, r): minimum palindrome partitions of string s[l..r]
// base cases:
//      l < r: INF (never select this choice)
//      l = r: 1
//  recurrence:
//      mp(l, r) = min(mp(l, i) + mp(i + 1, r)) for all i = l to r - 1
inline int solveM(int l, int r)
{
    debug03++;
    if (l > r) return INF;

    if (l == r)
        return 1;

    int &ans = mp[l][r];
    if (ans != -1) {
        debug02++;
        return ans;
    }

    // base case: a palindrome itself
    if (isp[l][r] == 1) {
        debug01++;
        ans = 1;
        return ans;
    }

    ans = INF;
    int left = solveM(l, r - 1) + 1;
    int right = solveM(l + 1, r) + 1;
    int mid = solveM(l + 1, r - 1) + 2;
    printf("l:%d r:%d| %d %d %d\n", l, r, left, right, mid);
    if (left < ans)
        ans = left;
    if (right < ans)
        ans = right;
    if (mid < ans)
        ans = mid;
    return ans;
}

int main() {
    int n;
    char tmp;
    scanf("%d%c", &n, &tmp);
    while (n--) {
        fgets(line, LIM, stdin);
        // strip the newline
        int len = strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = 0;
            len--;
        }

        memset(mp, 0xff, sizeof(mp)); // all -1
        solveP(len);
        printf("     ");
        for (int j = 0; j < len; j++)
            printf("%3d ", j);
        printf("\n--------------------------------\n");
        for (int i = 0; i < len; i++) {
            printf("%3d| ", i);
            for (int j = 0; j < len; j++)
                printf("%3d ", isp[i][j]);
            printf("\n");
        }
        printf("\n");
        printf("%d\n", solveM(0, len-1));
        printf("     ");
        for (int j = 0; j < len; j++)
            printf("%3d ", j);
        printf("\n--------------------------------\n");
        for (int i = 0; i < len; i++) {
            printf("%3d| ", i);
            for (int j = 0; j < len; j++)
                printf("%3d ", mp[i][j]);
            printf("\n");
        }
        //printf("%lu %lu %lu\n", debug01, debug02, debug03);
    }
    return 0;
}

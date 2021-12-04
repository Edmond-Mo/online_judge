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

int solveP(int len)
{
}

int solveM(int l, int r)
{
    if (l > r) return INF;

    if (l == r)
        return 1;

    int &ans = mp[l][r];
    if (ans != -1) return ans;

    // base case: a palindrome itself
    if (isp[l][r] == 1) {
        printf("%d %d\n", l, r);
        ans = 1;
        return ans;
    }

    ans = INF;
    for (int i = l; i < r; i++) {
        int left = solveM(l, i);
        int right = solveM(i + 1, r);
        ans = min(ans, left + right);
    }

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

        memset(isp, 0xff, sizeof(isp));
        memset(mp, 0xff, sizeof(mp));
        printf("%d\n", solveM(0, len-1));
    }
    return 0;
}
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

int main() {
    int tc = 1;
    int n;
    char tmp;
    scanf("%d%c", &n, &tmp);
    while (tc <= n) {
        char team[24];
        char judge[24];
        fgets(team, 24, stdin);
        fgets(judge, 24, stdin);
        if (strcmp(team, judge) == 0)
            printf("Case %d: Yes\n", tc);
        else {
            int i = 0;
            int j = 0;
            int tl = strlen(team);
            int jl = strlen(judge);
            bool matchWOSpace = true;
            while (i < tl && j < jl) {
                if (team[i] == ' ') {
                    i++;
                    continue;
                }
                if (judge[j] == ' ') {
                    j++;
                    continue;
                }
                if (team[i] != judge[j]) {
                    matchWOSpace = false;
                    break;
                }
                i++; j++;
            }
            if (matchWOSpace && (i == tl) && j == jl)
                printf("Case %d: Output Format Error\n", tc);
            else
                printf("Case %d: Wrong Answer\n", tc);
        }
        tc++;
    }
    return 0;
}

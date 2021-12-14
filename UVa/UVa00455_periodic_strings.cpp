#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int main() {
    char line[100];
    fgets(line, 100, stdin);
    int n;
    sscanf(line, "%d", &n);
    for (int i = 0; i < n; i++) {
        if (i > 0)
            printf("\n");
        fgets(line, 100, stdin); // blank line
        fgets(line, 100, stdin);
        int len = strlen(line);
        if (line[len-1] == '\n') {
            line[len-1] = 0;
            len--;
        }
        string s(line);
        string d(line);
        d += s;
        printf("%d\n", d.find(s, 1));
    }
}
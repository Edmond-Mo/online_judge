#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

inline void reverse(string &s) {
    int sz = s.size();
    for (int i = 0; i < sz / 2; i++) {
        int j = sz - i - 1;
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
}

inline bool ispali(string s) {
    int l = 0;
    int r = s.size() - 1;
    bool isP = true;
    while (l < r) {
        if (s[l] != s[r]) {
            isP = false;
            break;
        }
        l++; r--;
    }
    return isP;
}

int main() {
    int tc;
    char tmp;
    scanf("%d%c", &tc, &tmp);
    while (tc--) {
        char w[16];
        fgets(w, 16, stdin);
        int len = strlen(w);
        if (w[len - 1] == '\n') {
            w[len - 1] = 0;
            len--;
        }
        string s(w);
        bool found = false;
        int cnt = 0;
        unsigned int n;
        while (!found) {
            if (ispali(s)) {
                found = true;
                break;
            }
            n = stoul(s);
            reverse(s);
            unsigned int m = stoul(s);
            n += m;
            s = to_string(n);
            cnt++;
        }
        printf("%d %s\n", cnt, s.c_str());
    }
    return 0;
}

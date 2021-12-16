#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

inline bool isdivisor(const char *s, int len, int sz) {
    int i = len;
    while (i < sz) {
        for (int k = 0 ; k < len; k++) {
            if (s[k] != s[i]) {
                return false;
            }
            i++;
        }
    }

    return true;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    while (1) {
        string s;
        cin >> s;
        if (s[0] == '.') break;
        if (s.size() == 1) {
            cout << "1\n";
            continue;
        }
        int sz = s.size();
        int len = 1;
        for (; len <= sz; len++) {
            if (sz % len != 0)
                continue;
            if (isdivisor(s.c_str(), len, sz)) {
                break;
            }
        }

        cout <<  sz / len << "\n";
    }
    return 0;
}

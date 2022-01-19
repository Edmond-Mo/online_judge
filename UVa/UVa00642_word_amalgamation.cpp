#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;

#define PAT "XXXXXX"

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    unordered_map<string, vector<string>> mp;

    while (1) {
        string s;
        cin >> s;
        if (s.compare(PAT) != 0) {
            string key = s;
            sort(key.begin(), key.end());
            if (mp.find(key) == mp.end()) {
                mp.emplace(key, vector<string>());
            }
            mp[key].push_back(s);
        }
        else {
            break;
        }
    }

    while (1) {
        string scrambled;
        cin >> scrambled;
        if (scrambled.compare(PAT) == 0)
            break;
        sort(scrambled.begin(), scrambled.end());
        if (mp.find(scrambled) == mp.end()) {
            cout << "NOT A VALID WORD\n";
        }
        else {
            sort(mp[scrambled].begin(), mp[scrambled].end());
            for (auto itr = mp[scrambled].begin();
                 itr != mp[scrambled].end();
                 itr++) {
                cout << *itr << "\n";
            }
        }
        cout << "******\n";
    }

    return 0;
}

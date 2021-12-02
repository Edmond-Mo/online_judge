#include <bits/stdc++.h>
using namespace std;

// convert all char to lower case
inline void convert(char *word, int sz) {
    for (int i = 0; i < sz; i++) {
        word[i] = tolower(word[i]);
    }
    int lut[26] = {0}; // DAT sort
    for (int i = 0; i < sz; i++) {
        lut[word[i] - 'a']++;
    }
    char *walker = word;
    for (int i = 0; i < 26; i++) {
        while (lut[i] > 0) {
            *walker++ = 'a' + i;
            lut[i]--;
        }
    }
}

int main() {
    char word[24];
    unordered_map<string, vector<string>> m;
    while (1) {
        scanf("%s", word);
        if (word[0] == '#')
            break;
        string orig(word);
        convert(word, strlen(word));
        string s(word);
        //printf("%s -> %s\n", orig.c_str(), s.c_str());
        if (m.find(s) == m.end()) {
            m.emplace(s, vector<string>());
        }
        // map from converted word (key) to a vector of original words
        m[s].push_back(orig);
    }

    vector<string> ana;
    for (auto itr : m) {
        if (itr.second.size() == 1) {
            ana.push_back(itr.second[0]);
        }
    }
    sort(ana.begin(), ana.end());
    for (auto itr : ana) {
        printf("%s\n", itr.c_str());
    }
    return 0;
}

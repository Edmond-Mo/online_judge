#include <bits/stdc++.h>
using namespace std;

char t[128] = {'\0'};

inline static void init() {
    t['A'] = 'A';
    t['E'] = '3';
    t['H'] = 'H';
    t['I'] = 'I';
    t['J'] = 'L';
    t['L'] = 'J';
    t['M'] = 'M';
    t['O'] = 'O';
    t['S'] = '2';
    t['T'] = 'T';
    t['U'] = 'U';
    t['V'] = 'V';
    t['W'] = 'W';
    t['X'] = 'X';
    t['Y'] = 'Y';
    t['Z'] = '5';
    t['1'] = '1';
    t['2'] = 'S';
    t['3'] = 'E';
    t['5'] = 'Z';
    t['8'] = '8';
}

int main() {
    char word[30];
    init();
    while (fgets(word, 30, stdin)) {
        bool isp = true;
        bool ism = true;
        int l = 0;
        if (strcmp(word, "\n") == 0)
            break;
        if (word[strlen(word)-1] == '\n') 
            word[strlen(word)-1] = '\0';
        int r = strlen(word) - 1;
        while ((l < r) && (isp || ism)) {
            if (word[l] != word[r])
                isp = false;
            if (t[word[l]] != word[r])
                ism = false;
            l++; r--;
        }
        if (l == r) {  // odd len string with a centered char
            if (t[word[l]] != word[r])
                ism = false;
        }


        if (isp && ism)
            printf("%s -- is a mirrored palindrome.", word);
        else if (ism)
            printf("%s -- is a mirrored string.", word);
        else if (isp)
            printf("%s -- is a regular palindrome.", word);
        else
            printf("%s -- is not a palindrome.", word);
        printf("\n\n");
    }
    return 0;
}

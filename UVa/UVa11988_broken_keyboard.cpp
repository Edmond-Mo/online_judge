#include <bits/stdc++.h>
using namespace std;

char line[100020];
char s1[100020];
char s2[100020];
int sz1;
int sz2;

void push1(char v) {
    s1[sz1++] = v;
}

char pop1(void) {
    sz1--;
    return s1[sz1];
}

void push2(char v) {
    s2[sz2++] = v;
}

char pop2(void) {
    sz2--;
    return s2[sz2];
}

int main() {
    while (fgets(line, 100020, stdin) != NULL) {
        char *p = line;
        int cnt = 0;
        sz1 = sz2 = 0;
        while (*p != '\0') {
            if (*p == '[') {
                cnt++;
                while (sz1 > 0) {
                    push2(pop1());
                }
            }
            else if (*p == ']') {
                cnt++;
                while (sz2 > 0) {
                    push1(pop2());
                }
            }
            else if (*p != '\n') {
                push1(*p);
            }
            p++;
        }
        while (sz2 > 0) {
            push1(pop2());
        }
        s1[sz1] = '\0';
        printf("%s\n", s1);
    }
}
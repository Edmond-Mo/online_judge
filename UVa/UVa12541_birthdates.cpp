#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

#define NAME_SZ 20

struct Birthdate {
    int dd;
    int mm;
    int yyyy;
    char name[NAME_SZ];
};

typedef vector<Birthdate> vb;

int main() {
    int n;
    scanf("%d", &n);
    vb v;
    v.assign(n, Birthdate());
    for (int i = 0; i < n; i++) {
        Birthdate &b = v[i];
        scanf("%s %d %d %d", b.name, &(b.dd), &(b.mm), &(b.yyyy));
    }

//    for (int i = 0; i < v.size(); i++) {
//        printf("%s %d %d %d\n", v[i].name, v[i].dd, v[i].mm, v[i].yyyy);
//    }

    sort(v.begin(), v.end(),
        [](const Birthdate& a, const Birthdate& b) {
            if (a.yyyy < b.yyyy)
                return true;
            if (a.yyyy == b.yyyy) {
                if (a.mm < b.mm)
                    return true;
                if (a.mm == b.mm) {
                    if (a.dd < b.dd)
                        return true;
                }
            }

            return false;
        });

//    for (int i = 0; i < v.size(); i++) {
//        printf("%s %d %d %d\n", v[i].name, v[i].dd, v[i].mm, v[i].yyyy);
//    }
    printf("%s\n", v.back().name);
    printf("%s\n", v.front().name);
    return 0;
}



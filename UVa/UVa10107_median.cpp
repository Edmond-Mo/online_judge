#include <algorithm>
#include <cstdio>
#include <vector>

int main() {
    unsigned int n;
    std::vector<unsigned int> v;
    while (scanf("%u", &n) != EOF) {
        v.push_back(n);
        std::sort(v.begin(), v.end());
        int sz = v.size();
        if (sz & 1) {
            printf("%u\n", v[sz>>1]);
        }
        else {
            printf("%u\n", (v[sz>>1] + v[(sz>>1)-1]) >> 1);
        }
    }
    return 0;
}


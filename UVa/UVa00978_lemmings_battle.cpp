#include <bits/stdc++.h>
using namespace std;

int main() {
    int tc;
    scanf("%d", &tc);

    while (tc--) {
        int b, sg, sb;
        multiset<int, greater<int> > green;
        multiset<int, greater<int> > blue;
        scanf("%d %d %d", &b, &sg, &sb);
        for (int i = 0; i < sg; i++) {
            int p;
            scanf("%d", &p);
            green.insert(p);
        }
        for (int i = 0; i < sb; i++) {
            int p;
            scanf("%d", &p);
            blue.insert(p);
        }

        // while both teams have some soldiers left...
        while (!green.empty() && !blue.empty()) {
            // do battle!
            int party = b;
            int gcnt = green.size();
            int bcnt = blue.size();
            party = min(party, gcnt);
            party = min(party, bcnt);
            int i = 0;
            auto gi = green.begin();
            auto bi = blue.begin();
            vector<int> greenies;
            vector<int> blues;
            for (; i < party; i++, gi++, bi++) {
                int survivor;
                if (*gi > *bi) {
                    survivor = *gi - *bi;
                    greenies.push_back(survivor);
                }
                else if (*bi > *gi) {
                    survivor = *bi - *gi;
                    blues.push_back(survivor);
                }
            }
            green.erase(green.begin(), gi);
            blue.erase(blue.begin(), bi);
            green.insert(greenies.begin(), greenies.end());
            blue.insert(blues.begin(), blues.end());
        }

        if (!green.empty()) {
            printf("green wins\n");
            for (auto gi = green.begin(); gi != green.end(); gi++) {
                printf("%d\n", *gi);
            }
        }
        else if (!blue.empty()) {
            printf("blue wins\n");
            for (auto bi = blue.begin(); bi != blue.end(); bi++) {
                printf("%d\n", *bi);
            }
        }
        else {
            printf("green and blue died\n");
        }

        if (tc > 0)
            printf("\n");
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

int main() {
    vi num;
    vi greedyList;
    vi greedyIdx;
    vi parent;
    int n;
    int i = 0;
    while (scanf("%d", &n) != EOF) {
        num.push_back(n);
        parent.push_back(-1);
        auto itr = lower_bound(greedyList.begin(), greedyList.end(), n);
        int pos = itr - greedyList.begin();
        if (itr == greedyList.end()) {  // if new num greater than all num in greedy list
            greedyList.push_back(n);    // add new num to greedy list
            greedyIdx.push_back(i);
        }
        else {
            greedyList[pos] = n;        // replace with a better (smaller) candidate
            greedyIdx[pos] = i;
        }
        if (pos > 0)
            parent[i] = greedyIdx[pos - 1];
        i++;
    }
    // construct the LIS
    int p = greedyIdx.back();
    vi ans;
    while (parent[p] >= 0) {
        ans.push_back(num[p]);
        p = parent[p];
    }
    ans.push_back(num[p]);
    printf("%d\n-\n", greedyList.size());
    for (auto ri = ans.rbegin(); ri != ans.rend(); ri++) {
        printf("%d\n", *ri);
    }

    return 0;
}
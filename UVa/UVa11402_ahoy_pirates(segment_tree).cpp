#include <bits/stdc++.h>
using namespace std;

typedef vector<unsigned> vi;
//typedef vector<vi> vvi;

enum {
    OP_NOP,
    OP_BUC,
    OP_BAR,
    OP_INV,
};

class SegmentTree {
private:
    vi arr;
    vi tree;
    vi lazy;
    unsigned n;

    void buildTree(unsigned root, unsigned low, unsigned high) {
        if (low == high) {
            tree[root] = arr[low];
            return;
        }

        unsigned mid = (low + high) >> 1;
        unsigned left = root << 1;
        unsigned right = left + 1;
        buildTree(left, low, mid);
        buildTree(right, mid + 1, high);
        tree[root] = tree[left] + tree[right];
    }

    void propagate(unsigned root, unsigned low, unsigned high) {
        if (lazy[root] == OP_NOP)
            return;

        if (lazy[root] == OP_BUC) {
            tree[root] = high - low + 1;
        }
        else if (lazy[root] == OP_BAR) {
            tree[root] = 0;
        }
        else if (lazy[root] == OP_INV) {
            tree[root] = high - low + 1 - tree[root];
        }

        if (high != low) {
            unsigned left = root << 1;
            unsigned right = left + 1;
            if (lazy[root] == OP_BUC || lazy[root] == OP_BAR) {
                lazy[left] = lazy[right] = lazy[root];
            }
            else if (lazy[root] == OP_INV) {
                if (lazy[left] == OP_INV)
                    lazy[left] = OP_NOP;
                else if (lazy[left] == OP_BUC)
                    lazy[left] = OP_BAR;
                else if (lazy[left] == OP_BAR)
                    lazy[left] = OP_BUC;
                else if (lazy[left] == OP_NOP)
                    lazy[left] = OP_INV;

                if (lazy[right] == OP_INV)
                    lazy[right] = OP_NOP;
                else if (lazy[right] == OP_BUC)
                    lazy[right] = OP_BAR;
                else if (lazy[right] == OP_BAR)
                    lazy[right] = OP_BUC;
                else if (lazy[right] == OP_NOP)
                    lazy[right] = OP_INV;
            }
        }

        lazy[root] = OP_NOP;
    }

    unsigned query(unsigned root, unsigned nodeLow, unsigned nodeHigh, unsigned queryLow, unsigned queryHigh) {
        propagate(root, nodeLow, nodeHigh);

        if (queryLow > nodeHigh || queryHigh < nodeLow)
            return 0;

        if (queryLow <= nodeLow && queryHigh >= nodeHigh)
            return tree[root];

        unsigned mid = (nodeLow + nodeHigh) >> 1;
        unsigned returnLeft = query(root << 1, nodeLow, mid, queryLow, queryHigh);
        unsigned returnRight = query((root << 1) + 1, mid + 1, nodeHigh, queryLow, queryHigh);

        return returnLeft + returnRight;
    }

    void update(unsigned root, unsigned nodeLow, unsigned nodeHigh, unsigned updateLow, unsigned updateHigh, unsigned value) {
        propagate(root, nodeLow, nodeHigh);

        if (updateLow > nodeHigh || updateHigh < nodeLow)
            return;

        if (updateLow <= nodeLow && updateHigh >= nodeHigh) {
            lazy[root] = value;
            propagate(root, nodeLow, nodeHigh);
            return;
        }

        unsigned mid = (nodeLow + nodeHigh) >> 1;
        unsigned left = root << 1;
        unsigned right = left + 1;
        update(left, nodeLow, mid, updateLow, updateHigh, value);
        update(right, mid + 1, nodeHigh, updateLow, updateHigh, value);

        tree[root] = tree[left] + tree[right];
    }

public:
    SegmentTree(const vi &in) {
        arr = in;
        n = in.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, OP_NOP);
        buildTree(1, 0, n - 1);
    }

    unsigned query(unsigned low, unsigned high) {
        return query(1, 0, n - 1, low, high);
    }

    void update(unsigned low, unsigned high, unsigned value) {
        update(1, 0, n - 1, low, high, value);
    }
};

int main() {
    int tc, M, T, Q;
    char buf[500];
    char tmp;

    scanf("%d%c", &tc, &tmp);

    for (int t = 1; t <= tc; t++) {
        vi arr;
        scanf("%d%c", &M, &tmp);
        while (M--) {
            scanf("%d%c", &T, &tmp);
            fgets(buf, 100, stdin);
            int len = strlen(buf) - 1; // - the \n
            for (int i = 0; i < T; i++) {
                for (int j = 0; j < len; j++) {
                    arr.push_back((unsigned)(buf[j] - '0'));
                }
            }
        }

        SegmentTree st(arr);
        scanf("%d%c", &Q, &tmp);
        printf("Case %d:\n", t);
        int qi = 1;
        for (int q = 0; q < Q; q++) {
            char op;
            int a, b;
            scanf("%c %d %d%c", &op, &a, &b, &tmp);
            switch (op) {
                case 'F':
                    st.update(a, b, OP_BUC);
                    break;
                case 'E':
                    st.update(a, b, OP_BAR);
                    break;
                case 'I':
                    st.update(a, b, OP_INV);
                    break;
                case 'S':
                    printf("Q%d: %d\n", qi, st.query(a , b));
                    qi++;
                    break;
            }
        }
    }

    return 0;
}
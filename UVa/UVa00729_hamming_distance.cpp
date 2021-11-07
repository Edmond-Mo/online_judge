#include <bits/stdc++.h>
using namespace std;

typedef unsigned int uint;
typedef vector<uint> vi;

vi tbl;

void hamming(uint pos, uint bits, uint len, bitset<16> &bs)
{
    if (bits == 0) {
        //printf("%s\n", &(bs.to_string().c_str()[16 - len]));
        tbl[bs.to_ulong()] = 1;
        return;
    }

    if (pos >= len)
        return;

    for (uint i = pos; i < len; i++) {
        bs[i] = 1;
        hamming(i + 1, bits - 1, len, bs);
        bs[i] = 0;
    }
}

int main() {
    bitset<16> bs;
    char tmp;
    char buf[64];
    uint tc, N, H;

    scanf("%u%c", &tc, &tmp);
    while (tc--) {
        bs.reset();
        tbl.assign(66000, 0);
        fgets(buf, 64, stdin);  // blank line
        scanf("%u %u%c", &N, &H, &tmp);
        uint cnt = pow(2, N) + 1;
        hamming(0, H, N, bs);
        for (int i = 0; i < cnt; i++) {
            if (tbl[i]) {
                bitset<16> temp(i);
                printf("%s\n", &(temp.to_string().c_str()[16 - N]));
            }
        }
        if (tc) printf("\n");
    }
}
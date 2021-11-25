#include <bits/stdc++.h>
using namespace std;
#define N 1000000
bitset<1000010> bs;

int main() {
	int single, repeat;
	int start, end, interval;
	int conflict;
	while (scanf("%d %d", &single, &repeat), (single || repeat)) {
		conflict = 0;
		for (int i = 0; i < single; i++) {
			scanf("%d %d", &start, &end);

			if (conflict) continue;

			for (int b = start; b < end; b++) {
				if (bs[b]) {
					conflict = 1;
				}
				else {
					bs[b] = 1;
				}
			}
		}

		for (int i = 0; i < repeat; i++) {
			scanf("%d %d %d", &start, &end, &interval);

			if (conflict) continue;

			if ((end - start) > interval) {
				conflict = 1;
				continue;
			}

			while (1) {
				if (start >= N)
					break;
				if (end > N)
					end = N;
				for (int b = start; b < end; b++) {
					if (bs[b]) {
						conflict = 1;
						break;
					}
					else {
						bs[b] = 1;
					}
				}
				start += interval;
				end += interval;
			}
		}

		if (conflict) {
			printf("CONFLICT\n");
		}
		else {
			printf("NO CONFLICT\n");
		}

		bs.reset();
	}

	return 0;
}

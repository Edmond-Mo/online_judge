#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

#define LIM 10000
char line[LIM];

int main() {
	int n;
	cin >> n;
	while (n--) {
		string line;
		cin >> line;
		sort(line.begin(), line.end());
		do {
			cout << line << "\n";
		} while (next_permutation(line.begin(), line.end()));
	}
	return 0;
}


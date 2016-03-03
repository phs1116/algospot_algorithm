#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int cache[101][101], N[101][101];
int tryanglepath(int y, int x) {
	if (y == n-1) return N[y][x];
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	return	ret = N[y][x] + max(tryanglepath(y + 1, x), tryanglepath(y + 1, x + 1));
}
int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int y = 0; y < n; y++)
			for (int x = 0; x <= y; x++)
				cin >> N[y][x];
		int ret = tryanglepath(0, 0);
		cout << ret << endl;
	}
}
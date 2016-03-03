#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int cache[101][101], N[101][101];
int tryanglepath(int y, int x) {
	if (y == n - 1) return N[y][x];
	int& ret = cache[y][x];
	if (ret != -1) return ret;
	return	ret = N[y][x] + max(tryanglepath(y + 1, x), tryanglepath(y + 1, x + 1));
}


int countCache[101][101];
int countpath(int y, int x) {


	if (y == n - 1) return 1;

	int& ret = countCache[y][x];

	if (ret != -1) return ret;
	// 경로 한개
	ret = 0;
	if (tryanglepath(y + 1,x) >= tryanglepath(y + 1,x + 1))
		ret += countpath(y + 1, x);

	if (tryanglepath(y + 1,x + 1) >= tryanglepath(y + 1,x))// 경로 한개
		ret += countpath(y + 1, x + 1);
	
	return ret;
}


int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		memset(cache, -1, sizeof(cache));
		memset(countCache, -1, sizeof(countCache));
		cin >> n;
		for (int y = 0; y < n; y++)
			for (int x = 0; x <= y; x++)
				cin >> N[y][x];
		int ret = countpath(0, 0);
		cout << ret << endl;
	}
}
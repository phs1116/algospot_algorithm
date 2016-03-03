#include <iostream>

using namespace std;


const int MOD = 1000000007;

int cache[101];

int tiling2(int width) {
	if (width <= 1) return 1;

	int& ret = cache[width];

	if (ret != -1) return ret;

	return ret = (tiling2(width - 1) + tiling2(width - 2)) % MOD;
}

int main() {

	int testcase,width,ret;
	cin >> testcase;

	while (testcase--) {
		memset(cache, -1, sizeof(cache));
		cin >> width;
		ret = tiling2(width);

		cout << ret << endl;

	}
}
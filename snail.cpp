#include <iostream>

using namespace std;
int m, n;
long double cache[1001][1001];
long double Snail(int days, int up) {
	if (days == m)
		return up >= n ? 1 : 0;
	long double& ret = cache[days][up];
	if (ret != -1.0)
		return ret;
	ret = .75*Snail(days + 1, up + 2) + .25*Snail(days + 1, up + 1);
	return ret;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		//fill(cache[0], cache[0] + 1000 * 1000, -1);
		for (int i = 0; i < 1001; ++i)
			for (int j = 0; j < 1001; ++j)
				cache[i][j] = -1;
		cin >> n >> m;
		printf("%0.10Lf\n", Snail(0, 0));
	}
}
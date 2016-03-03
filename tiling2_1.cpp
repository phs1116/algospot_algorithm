#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
int Width;
int cache[101];
int tiling(int xpos) {
	
	if (xpos == Width) return 1;

	if (xpos > Width) return 0;

	int& ret = cache[xpos];

	if (ret != -1) return ret;
	
	return ret = (tiling(xpos + 2) + tiling(xpos + 1)) % MOD;
}

int main() {

	int testcase;
	cin >> testcase;

	while (testcase--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> Width;
		cout << tiling(0) << endl;

	}
}
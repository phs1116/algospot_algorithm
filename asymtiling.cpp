#include <iostream>

using namespace std;


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


int Asymtiling(int width) {
	//È¦¼öÀÎ ´ëÄªÀÎ ¿ÞÂÊºÎºÐÀÇ °æ¿ìÀÇ¼ö
	if ((width) % 2 == 1)
		return (tiling(0) - tiling(width / 2) + MOD) % MOD;

	//Â¦¼ö ´ëÄªÀÎ°æ¿ì
	else if ((width) % 2 == 0) {
		//return	(tiling(0) - tiling(width / 2 - 1) + MOD) % MOD;

		//int ret = (tiling(width / 2 + 1)  +  MOD) % MOD;
		int ret = (tiling(width / 2) + MOD) % MOD;
		return ret;
	}
}


int main() {
	int testcase;
	cin >> testcase;
	while (testcase--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> Width;
		cout << Asymtiling(Width) << endl;
	}
}
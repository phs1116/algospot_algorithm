#include <iostream>
#include <algorithm>

using namespace std;


int n, tryangle[100][100];
int cache[100][100];


int path(int y, int x) {
	if (y == n - 1) return tryangle[y][x];

	int& ret = cache[y][x];

	if (ret != -1)
		return ret;

	return ret = tryangle[y][x] + max(path(y + 1, x), path(y + 1, x + 1));
}
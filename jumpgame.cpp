#include <iostream>


using namespace std;


int n,board[100][100];

int cache[100][100];


int jump(int y, int x) {

	if (y > n || x > n)
		return 0;

	if (y == n - 1 && x == n - 1)
		return 1;


	//캐시 확인.
	int& ref = cache[y][x];
	if (ref != -1) return ref;

	int jumpSize = board[y][x];

	//메모이제이션
	return ref = jump(y, x + jumpSize) || jump(y + jumpSize, x);

}


int main() {
	int testcase, ret;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		memset(board, -1, sizeof(board));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf_s("%d", &board[i][j]);
			}
		}
		ret = jump(0, 0);

		printf(ret == 1 ? "YES\n" : "NO\n");
	}

	return 0;
}
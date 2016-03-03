#include <iostream>
#include <cstring>
using namespace std;



int n, cache[100][100], A[100][100];


int jumpGame(int y, int x) {
	
	//���������� 1 ��ȯ
	if (y == n - 1 && x == n - 1) return 1;

	//���� ����� 0 ��ȯ
	if (y >= n || x >= n) return 0;

	int& ret = cache[y][x];

	if (ret != -1) return ret;

	return ret = jumpGame(y, x + A[y][x]) || jumpGame(y + A[y][x], x);
}



int main() {

	int testcase, ret;
	cin >> testcase;
	while (testcase--) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				cin >> A[y][x];

		ret = jumpGame(0, 0);
		cout << ((ret == 1) ? "YES" : "NO")<<endl;
	}


}
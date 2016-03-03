#include <iostream>
#include <algorithm>
using namespace std;



//���� �������� �ּҰ� ������ ���ؼ� �� ������ ����� ���;� �Ѵ�.


const int INF = 987654321;

int n, A[101], pSum[101], pqpSum[101];

void calc() {
	sort(A, A + n); // �迭 ����
	pSum[0] = A[0];
	pqpSum[0] = A[0] * A[0];
	for (int i = 1; i < n; i++) {
		pSum[i] = pSum[i - 1] + A[i];
		pqpSum[i] = pqpSum[i - 1] + A[i] * A[i];
	}
}

int minValue(int start, int end) {

	int sum = pSum[end] - (start == 0 ? 0 : pSum[start - 1]);
	int qpSum = pqpSum[end] - (start == 0 ? 0 : pqpSum[start - 1]);

	int avg = (int)(0.5 + (double)sum / (end - start + 1));
	int minV = qpSum - 2 * avg*sum + avg*avg*(end - start + 1);

	return minV;
}

int cache[101][11];

int Quantize(int start, int parts) {

	//������� : �� �������� �迭 ���� �������� ���
	if (start == n) return 0;
	//������� : ���ڹ迭�� ���Ҵµ� �������ִ� ��Ʈ�� ���°��.
	if (parts == 0) return INF;
	int& ret = cache[start][parts];
	if (ret != -1) return ret;

	ret = INF;

	for (int size = 1; size <= n - start; ++size) {
		ret = min(ret, minValue(start, start + size - 1) + Quantize(start + size, parts - 1));

	}

	return ret;
}

int main() {
	int testcase;
	int parts;
	cin >> testcase;

	while (testcase--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> n >> parts;
		for (int i = 0; i < n; i++)
			cin >> A[i];
		calc();
		int ret = Quantize(0, parts);

		cout << ret << endl;
	}
}
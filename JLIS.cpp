#include <iostream>
#include <algorithm>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, A[100], B[100];

int cache[101][101];

int lis(int indexA, int indexB) {


	//������� : �ѱ��̿� �����ϸ� 0 ����

	int& ret = cache[indexA][indexB];//start ���������� �ѱ���

	if (ret != -1)
		return ret;

	int a = indexA == -1 ? NEGINF : A[indexA];
	int b = indexB == -1 ? NEGINF : B[indexB];
	ret = 1;

	int maxElement = max(a, b);

	for (int next = indexA; next < n; ++next) {
		// A[next] > A[start]�� �����ϰ� start�� ù ���ڰ� 0�ϰ�쿡��
		//�׻� A�迭�� ù��° ���ڿ͸� ���ϹǷ�, ù��° ���� ������ �κ����� ������ ��Ÿ����
		//���� �Ѿ��� �������� �������� �κ� ���������� ������� ���� �������� �������� �񱳸� �����ؾ��Ѵ�.
		// �̿� ���� �ذ�å�� lis2
		if (A[next] > maxElement) {
			ret = max(ret, lis(next, indexB) + 1);
		}
	}

	for (int next = indexB; next < n; ++next) {
		// A[next] > A[start]�� �����ϰ� start�� ù ���ڰ� 0�ϰ�쿡��
		//�׻� A�迭�� ù��° ���ڿ͸� ���ϹǷ�, ù��° ���� ������ �κ����� ������ ��Ÿ����
		//���� �Ѿ��� �������� �������� �κ� ���������� ������� ���� �������� �������� �񱳸� �����ؾ��Ѵ�.
		// �̿� ���� �ذ�å�� lis2
		if (A[next] > maxElement) {
			ret = max(ret, lis(indexA, next) + 1);
		}
	}





	return ret;
}


int cache2[101];

int lis2(int start) {


	//�� �Լ�����  cache2[0]�� ��� ������������ �ִ� ���̸� �����ϰ� �ȴ�.
	int& ret = cache2[start + 1];//start ���������� �ѱ���

	if (ret != -1)
		return ret;


	ret = 1;

	for (int next = start + 1; next < n; ++next) {
		//ó���̴� �Ѿ��� ���� A[start]������ �����Ѵٰ� �����Ѵ�.
		//A[-1]�̶� ���� �����Ƿ� A[-1]�� �ִٰ� ����, A[i]������ ��� �Ѿ��� ���� A[start]���� ũ�Ƿ� ��� ���۰��� ���� ����Ѵ�.
		if (start == -1 || A[next] > A[start])
		{
			ret = max(ret, lis2(next) + 1);
		}
	}


	return ret;
}

int main() {

	cin >> n;

	memset(cache, -1, sizeof(cache));
	memset(cache2, -1, sizeof(cache2));
	//cache2[0] = -987654321;
	for (int i = 0; i < n; i++)
		cin >> A[i];


	int ab = lis(0);
	printf("%d\n", ab);



	//A[-1]�� ��쿡�� 1�� ���ع����Ƿ� 1�� ����� ���� ���� ����.
	int ab2 = lis2(-1) - 1;
	printf("%d\n", ab2);
}
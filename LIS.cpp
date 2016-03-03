#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n,A[100];

int cache[100];

int lis(int start) {
	

	//������� : �ѱ��̿� �����ϸ� 0 ����

	int& ret = cache[start];//start ���������� �ѱ���

	if (ret != -1)
		return ret;


	ret = 1;

	for (int next = start; next < n; ++next) {
		// A[next] > A[start]�� �����ϰ� start�� ù ���ڰ� 0�ϰ�쿡��
		//�׻� A�迭�� ù��° ���ڿ͸� ���ϹǷ�, ù��° ���� ������ �κ����� ������ ��Ÿ����
		//���� �Ѿ��� �������� �������� �κ� ���������� ������� ���� �������� �������� �񱳸� �����ؾ��Ѵ�.
		// �̿� ���� �ذ�å�� lis2
		if ( A[next] > A[start]) {
			ret = max(ret, lis(next) + 1);
		}
	}


	return ret;
}


int cache2[101];

int lis2(int start) {


	//�� �Լ�����  cache2[0]�� ��� ������������ �ִ� ���̸� �����ϰ� �ȴ�.
	int& ret = cache2[start+1];//start ���������� �ѱ���

	if (ret != -1)
		return ret;


	ret = 1;

	for (int next = start+1; next < n; ++next) {
		//ó���̴� �Ѿ��� ���� A[start]������ �����Ѵٰ� �����Ѵ�.
		//A[-1]�̶� ���� �����Ƿ� A[-1]�� �ִٰ� ����, A[i]������ ��� �Ѿ��� ���� A[start]���� ũ�Ƿ� ��� ���۰��� ���� ����Ѵ�.
		 if(start == -1 || A[next] > A[start])
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

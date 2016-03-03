#include <iostream>
#include <algorithm>

using namespace std;

const long long NEGINF = numeric_limits<long long>::min();
int n, A[100], B[100];

int cache[101][101];

int lis(int indexA, int indexB) {


	//기저사례 : 총길이에 도달하면 0 리턴

	int& ret = cache[indexA][indexB];//start 지점에서의 총길이

	if (ret != -1)
		return ret;

	int a = indexA == -1 ? NEGINF : A[indexA];
	int b = indexB == -1 ? NEGINF : B[indexB];
	ret = 1;

	int maxElement = max(a, b);

	for (int next = indexA; next < n; ++next) {
		// A[next] > A[start]로 시작하고 start의 첫 숫자가 0일경우에는
		//항상 A배열의 첫번째 숫자와만 비교하므로, 첫번째 숫자 기준의 부분증가 수열만 나타난다
		//따라서 한없이 작은값을 기준으로 부분 증가수열을 만들려면 가장 작은값을 기준으로 비교를 시작해야한다.
		// 이에 대한 해결책이 lis2
		if (A[next] > maxElement) {
			ret = max(ret, lis(next, indexB) + 1);
		}
	}

	for (int next = indexB; next < n; ++next) {
		// A[next] > A[start]로 시작하고 start의 첫 숫자가 0일경우에는
		//항상 A배열의 첫번째 숫자와만 비교하므로, 첫번째 숫자 기준의 부분증가 수열만 나타난다
		//따라서 한없이 작은값을 기준으로 부분 증가수열을 만들려면 가장 작은값을 기준으로 비교를 시작해야한다.
		// 이에 대한 해결책이 lis2
		if (A[next] > maxElement) {
			ret = max(ret, lis(indexA, next) + 1);
		}
	}





	return ret;
}


int cache2[101];

int lis2(int start) {


	//이 함수에선  cache2[0]은 모든 시작점에서의 최대 길이를 저장하게 된다.
	int& ret = cache2[start + 1];//start 지점에서의 총길이

	if (ret != -1)
		return ret;


	ret = 1;

	for (int next = start + 1; next < n; ++next) {
		//처음이는 한업이 작은 A[start]값부터 시작한다고 가정한다.
		//A[-1]이란 값은 없으므로 A[-1]이 있다고 가정, A[i]값들이 모두 한없이 작은 A[start]보다 크므로 모든 시작값을 경우로 계산한다.
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



	//A[-1]일 경우에도 1을 더해버리므로 1을 빼줘야 원래 값이 나옴.
	int ab2 = lis2(-1) - 1;
	printf("%d\n", ab2);
}
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 987654321;


string num;

//점수를 구하는 함수
int classify(int begin, int end) {

	string str = num.substr(begin, end - begin + 1);
	//모든 문자가 일치할경우.
	if (str == string(str.size(), str[0])) return 1;

	//1씩 단조증가하거나 단조 감소, 즉 등차수열이 1이거나 -1인경우
	//등차수열인지 확인

	bool progressive = true;
	bool alternating = true;

	for (int i = 0; i < str.size() - 1; i++) {
		//등차수열이 아니면 false
		if (str[i + 1] - str[i] != str[1] - str[0])
			progressive = false;
	}


	//단조증가면 2 반환
	if (progressive && abs(str[1] - str[0]) == 1)
		return 2;


	for (int i = 2; i < str.size(); i++) {
		if (str[i % 2] != str[i])
			alternating = false;
	}

	if (progressive) return 5;
	if (alternating) return 4;

	return 10;
}

int cache[100000];
int memorize(int begin) {

	// 기저사례 : 맨 마지막 문자면 0반환
	if (begin == num.size()) return 0;


	//메모이제이션
	int& ret = cache[begin];

	if (ret != -1)
		return ret;

	ret = INF;
	for (int i = 3; i <= 5; i++) {
		if (begin + i <= num.size())
			ret = min(ret, memorize(begin + i) + classify(begin, begin + i - 1));
	}

	return ret;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		num.clear();
		cin >> num;
		memset(cache, -1, sizeof(cache));
		cout << memorize(0) << endl;
	}
}
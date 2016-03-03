#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 987654321;


string num;

//������ ���ϴ� �Լ�
int classify(int begin, int end) {

	string str = num.substr(begin, end - begin + 1);
	//��� ���ڰ� ��ġ�Ұ��.
	if (str == string(str.size(), str[0])) return 1;

	//1�� ���������ϰų� ���� ����, �� ���������� 1�̰ų� -1�ΰ��
	//������������ Ȯ��

	bool progressive = true;
	bool alternating = true;

	for (int i = 0; i < str.size() - 1; i++) {
		//���������� �ƴϸ� false
		if (str[i + 1] - str[i] != str[1] - str[0])
			progressive = false;
	}


	//���������� 2 ��ȯ
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

	// ������� : �� ������ ���ڸ� 0��ȯ
	if (begin == num.size()) return 0;


	//�޸������̼�
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
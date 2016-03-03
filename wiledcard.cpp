#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cache[101][101];


string W, S;


int match(int w, int s) {

	int& ret = cache[w][s];
	if (ret != -1) return ret;

	//���ϵ�ī�� ���ڿ��� ���� �������� �ʾ������, ���ڿ��� ���� �������� �ʾ������ w�� ?�̰ų� �� ���ڰ� ������� ��� ����
	while (w < W.size() && s < S.size() &&( W[w] == '?' || W[w] == S[s])) {
		++w;
		++s;
	}

	if (W.size() == w) return ret = (S.size() == s ? 1:0); //b�� ���ڿ� ������ �����ؾ� true �ƴϸ� false


	//���� *�� �����ٸ�, �� ���ĸ� �˻�.
	if (W[w] == '*') {
		for (int skip = 0; s+skip <= S.size(); ++skip) {
			//substr�� length�� ���ڿ��� ����� ���� �� ���� ��ġ�� ����Ű�Եȴ�.
			// '*'���� ������ ���ڿ� ��ġ�ϴ� ���ڰ� ��Ÿ������ ����ؼ� ��.
			if (match(w + 1, s + skip)) {
				return ret = 1;
			}
		}
	}

	return 0;
}


int match2(int w, int s) {

	int& ret = cache[w][s];
	if (ret != -1) return ret;

	//���ϵ�ī�� ���ڿ��� ���� �������� �ʾ������, ���ڿ��� ���� �������� �ʾ������ w�� ?�̰ų� �� ���ڰ� ������� ��� ����
	if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
		ret = match2(w + 1, s + 1);

	if (W.size() == w) return ret = (S.size() == s ? 1 : 0); //b�� ���ڿ� ������ �����ؾ� true �ƴϸ� false


															 //���� *�� �����ٸ�, �� ���ĸ� �˻�.
	if (W[w] == '*') {
		//*�� �����ϰ� �Ѿ������ ���� *�� ��������� �� �ϳ��� �����ϸ� 1��ȯ
		if(match2(w+1,s) ||(s<S.size() && match(w,s+1))
				return ret = 1;
		}
	}

	return 0;
}


vector<string> output;

int main() {

	int i = 3;
	cin >> W;
	while (i--) {
		cin >> S;
		memset(cache, -1, sizeof(cache));
		int test = match(0, 0);
		if(test == 1) output.push_back(S);
	}

	printf("\n");
	for (int i = 0; i <= output.size(); i++) {
		cout << output.back() << endl;
		output.pop_back();
	}
}
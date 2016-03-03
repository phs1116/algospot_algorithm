#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void normalize(vector<int>& num) {


	num.push_back(0);//자릿수 증가를 위한 임시 공간.
	for (int i = 0; i < num.size(); i++) {
		if (num[i] < 0) {
			//- 자리수
			int borrow = (abs(num[i] + 9)) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow + 10;
		}
		else {
			num[i + 1] += num[i] / 10;//자리수 올림
			num[i] = num[i] % 10;
		}
	}

	//상위 자릿수의 0 제거
	while (num.size() > 1 && num.back() == 0) num.pop_back();


}


//단순 곱셈 알고리즘. 거꾸로 저장됨

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0); //a사이즈와 b사이즈 +1만큼 생성후 0으로초기화.
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}


	//자릿수 정규화
	//normalize(c);
	return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) {
	a.resize(max(a.size(), b.size() + k));
	for (int i = 0; i < b.size(); i++) {
		a[i + k] += b[i];
	}
	//normalize(a);
}


void subFrom(vector<int>& a, const vector<int>& b) {
	a.resize(max(a.size(), b.size()) + 1);
	if (a.size() < b.size()) return;

	for (int i = 0; i < b.size(); i++) {
		a[i] -= b[i];
	}
	//normalize(a);

}

vector<int> karatsuba(const vector<int>& a,const vector<int>& b) {
	int an = a.size(), bn = b.size();

	//b가 a보다 크면 두개를 바꿔 계산한다. 이게 더 빠르다.
	if (an < bn) return karatsuba(b, a);

	//기저사례 : a,b 둘중 하나가 비어있는 경우.(끝까지 다 곱함)

	if (an == 0 || bn == 0) return vector<int>();//빈 벡터 반환

	//숫자 자리수가 일정이상 작으면 단순 곱셈 알고리즘을 사용한다.
	if (an <= 50) return multiply(a, b);

	//자릿수를 반으로
	int half = an / 2;



	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());


	// b의 크기가 a보다 작으므로, a의 반 자리수보다 작으면 b의 전체 자리수를 넣음
	vector<int> b0(b.begin(), b.begin() + min<int>(half, b.size()));
	vector<int> b1(b.begin() + min<int>(half,b.size()), b.end());

	vector<int> z2 = karatsuba(a1, b1);
	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0);
	addTo(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);

	return ret;


}


//벡터a를 문자열로 변경.
string toString(vector<int> a) {
	string ret;
	while (a.size() > 1 && a.back() == 0) a.pop_back();
	for (int i = 0; i < a.size(); i++)
		ret += char('0' + a[a.size() - 1 - i]);
	return ret;
}

//문자열 s를 벡터로 변경.
vector<int> fromString(const string& s) {
	vector<int> ret;
	for (int i = 0; i < s.size(); i++)
		ret.push_back(s[i] - '0');
	reverse(ret.begin(), ret.end());
	return ret;
}


int hugs(const string& members, const string& fans) {
	int N = members.size(), M = fans.size();
	vector<int> A(N), B(M);
	for (int i = 0; i < N; i++) A[i] = (members[i] == 'M');
	for (int i = 0; i < M; i++) B[M - i - 1] = (fans[i] == 'M');

	vector<int> C = karatsuba(A, B);
	int allHugs = 0;
	for (int i = N - 1; i < M; i++) {
		
		if (C[i] == 0) {
			
			++allHugs;
		}
	}

	return allHugs;
}



vector<int> result;
string a, b;
int main()
{
	int c;
	cin >> c;
	while (c-- > 0)
	{
		cin >> a;
		cin >> b;
		result.push_back(hugs(a, b));
	}

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

	return 0;
}
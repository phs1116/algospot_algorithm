#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

void normalize(vector<int>& num) {


	num.push_back(0);//�ڸ��� ������ ���� �ӽ� ����.
	for (int i = 0; i < num.size(); i++) {
		if (num[i] < 0) {
			//- �ڸ���
			int borrow = (abs(num[i] + 9)) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow + 10;
		}
		else {
			num[i + 1] += num[i] / 10;//�ڸ��� �ø�
			num[i] = num[i] % 10;
		}
	}

	//���� �ڸ����� 0 ����
	while (num.size() > 1 && num.back() == 0) num.pop_back();


}


//�ܼ� ���� �˰���. �Ųٷ� �����

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() + 1, 0); //a������� b������ +1��ŭ ������ 0�����ʱ�ȭ.
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			c[i + j] += a[i] * b[j];
		}
	}


	//�ڸ��� ����ȭ
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

	//b�� a���� ũ�� �ΰ��� �ٲ� ����Ѵ�. �̰� �� ������.
	if (an < bn) return karatsuba(b, a);

	//������� : a,b ���� �ϳ��� ����ִ� ���.(������ �� ����)

	if (an == 0 || bn == 0) return vector<int>();//�� ���� ��ȯ

	//���� �ڸ����� �����̻� ������ �ܼ� ���� �˰����� ����Ѵ�.
	if (an <= 50) return multiply(a, b);

	//�ڸ����� ������
	int half = an / 2;



	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());


	// b�� ũ�Ⱑ a���� �����Ƿ�, a�� �� �ڸ������� ������ b�� ��ü �ڸ����� ����
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


//����a�� ���ڿ��� ����.
string toString(vector<int> a) {
	string ret;
	while (a.size() > 1 && a.back() == 0) a.pop_back();
	for (int i = 0; i < a.size(); i++)
		ret += char('0' + a[a.size() - 1 - i]);
	return ret;
}

//���ڿ� s�� ���ͷ� ����.
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
#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it) {

	char head = *it;
	++it;

	if (head == 'w' || head == 'b')
		return string(1, head);//head�� �ִ� ���ڸ� ������ ���ڿ� ��ȯ

	//���� ���δ� w�� b�� �ƴ� x�� ���ԵǾ��ִٸ� 4���� ����.

	string upperleft = reverse(it);
	string upperright = reverse(it);
	string underleft = reverse(it);
	string underright = reverse(it);

	return string("x") + underleft + underright + upperleft + upperright;
}


int main() {
	string st, at;

	int testcase;

	cin >> testcase;

	while (--testcase+1) {
		cin >> st;
		at = reverse(st.begin());
		cout << at<<endl;
	}

	return 1;
}
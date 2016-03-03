#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator& it) {

	char head = *it;
	++it;

	if (head == 'w' || head == 'b')
		return string(1, head);//head에 있는 글자를 포함한 문자열 반환

	//만약 전부다 w나 b가 아닌 x가 포함되어있다면 4개로 분할.

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
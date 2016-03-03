#include <iostream>
using namespace std;

//각 숫자들을 저장하는 배열.
long long cache[10];

void calc(int num, int ten) {
	while (num > 0) {
		cache[num % 10] += ten;
		num /= 10;
	}
}

void find(int start, int num, int ten) {
	while (start % 10 != 0 && start <= num) {
		calc(start,ten);
		++start;
	}
	//기저사례 : start가 num보다 크면 리턴.
	if (start > num) return;

	while (num % 10 != 9 && start <= num){
		calc(num,ten);
		--num;
	}
	for (int i = 0; i < 10; i++) {
		cache[i] += (num/10 - start/10 + 1) * ten;
	}
	find(start / 10, num / 10,ten * 10);

}

int main()
{
	int val;
	cin >> val;
	find(1,val,1);	
	for (int i = 0; i < 10; i++) {
		cout << cache[i] << " ";
	}
	cout << endl;
}


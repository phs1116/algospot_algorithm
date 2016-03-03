#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> h;


// ������������ �ذ�
//���ʰ� ������ ���� ������ �潺�� ���̰��.
int fence(int left, int right) {
	int mid = (left + right) / 2;


	//������� : left�� right�� ������ ������ �˻��Ѱ��.
	if (left == right) return h[left];

	int ret = max(fence(left, mid), fence(mid+1, right));


	//���� �ִ� ���̸� �������� ��,������� ���� ���� ���̸� ����.(�׷��� ���̱Ⱑ ������)
	int mleft = mid, mright = mid + 1;
	int curHeight = min(h[mleft], h[mright]);

	// ���� ������ m~m+1 ���̸� ������ ���簢���� ���� ���簢���� ũ�⸦ ��
	//���� �¿찡 left,rigth�� ��� ��� while���� ������� ���� ��� ���.
	ret = max(ret, curHeight * 2); 

	//������ �ݺ�.
	while (mleft > left && mright < right) {
		
		//���� ���� ���̰� �����ʺ��� �� ũ�ٸ�
		if ((h[mright + 1] < h[mleft - 1]) || right == mright) {
			curHeight = min(curHeight, h[--mleft]);
		}

		else if((h[mright + 1] >= h[mleft - 1]) || left == mleft) {
			curHeight = min(curHeight, h[++mright]);
		}


		ret = max(ret, curHeight * (mright - mleft + 1));

	}

	return ret;
	



}


int main() {
	int testcase;
	int fNum,input;
	cin >> testcase;
	
	while(--testcase+1) {
		cin >> fNum;
		h.resize(fNum);
		while (--fNum + 1) {
			scanf_s("%d",&input);
			h.push_back(input);
		}

		int result = fence(0, h.size() - 1);
		cout << result << endl;
		h.clear();
	}

	return 0;
}
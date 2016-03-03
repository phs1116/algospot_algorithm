#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<int> h;


// 분할정복으로 해결
//왼쪽과 오른쪽 끝을 가지고 펜스의 넓이계산.
int fence(int left, int right) {
	int mid = (left + right) / 2;


	//기저사례 : left와 right가 같으면 끝까지 검사한경우.
	if (left == right) return h[left];

	int ret = max(fence(left, mid), fence(mid+1, right));


	//구한 최대 넓이를 기점으로 좌,우높이중 낮은 쪽의 높이를 구함.(그래야 붙이기가 가능함)
	int mleft = mid, mright = mid + 1;
	int curHeight = min(h[mleft], h[mright]);

	// 구한 높이의 m~m+1 넓이를 가지는 직사각형과 기존 직사각형의 크기를 비교
	//만약 좌우가 left,rigth에 모두 닿아 while문이 실행되지 않을 경우 대비.
	ret = max(ret, curHeight * 2); 

	//끝까지 반복.
	while (mleft > left && mright < right) {
		
		//만약 왼쪽 높이가 오른쪽보다 더 크다면
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
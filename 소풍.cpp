#include <iostream>

using namespace std;

int n, m;
bool areFriends[10][10], taken[10];

int countPairings(bool taken[10]){
	int firstfree = -1; // 가장 첫 순번을 -1로 초기화
	for (int i = 0; i < n; i++) // 짝을 안지은 학생을 검사
		if (!taken[i]){ // 짝을 안지은 앞순번 학생을 찾으면
		firstfree = i; // firstfree에 그 인덱스를 대입
		break;
		}
	//기저 사례 : 모든 짝을 다 찾아줬을경우 -> 방법을 찾았으므로 1 리턴
	if (firstfree == -1) return 1;
	int ret = 0; // 짝을 구한 경우를 저장하는 변수
	for (int pairwith = firstfree + 1; pairwith < n; pairwith++){
		if (!taken[pairwith] && areFriends[firstfree][pairwith]){
			taken[firstfree] = taken[pairwith] = true; // taken[firstfree]와 taken[pairwith]를 짝지어줌
			ret += countPairings(taken); // 방금 짝을 지은 경우를 제외한 나머지 짝을 짓는경우를 계산.
			taken[firstfree] = taken[pairwith] = false;// taken[firstfree]와 taken[pairwith]가 아닌 다른 짝을 짓는 경우를 계산하기위해 false로
		}
	}
	return ret;
}

int main(){
	int count;
	cin >> count;
	while (count--){
		cin >> n >> m;
		memset(areFriends, false, sizeof(areFriends));
		for (int i = 0; i < m; i++){
			int a, b;
			cin >> a >> b;
			areFriends[a][b] = true;
			areFriends[b][a] = true;
		}
		memset(taken, false, sizeof(taken));
		cout << countPairings(taken) << endl;
	}
}
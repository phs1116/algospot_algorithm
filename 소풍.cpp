#include <iostream>

using namespace std;

int n, m;
bool areFriends[10][10], taken[10];

int countPairings(bool taken[10]){
	int firstfree = -1; // ���� ù ������ -1�� �ʱ�ȭ
	for (int i = 0; i < n; i++) // ¦�� ������ �л��� �˻�
		if (!taken[i]){ // ¦�� ������ �ռ��� �л��� ã����
		firstfree = i; // firstfree�� �� �ε����� ����
		break;
		}
	//���� ��� : ��� ¦�� �� ã��������� -> ����� ã�����Ƿ� 1 ����
	if (firstfree == -1) return 1;
	int ret = 0; // ¦�� ���� ��츦 �����ϴ� ����
	for (int pairwith = firstfree + 1; pairwith < n; pairwith++){
		if (!taken[pairwith] && areFriends[firstfree][pairwith]){
			taken[firstfree] = taken[pairwith] = true; // taken[firstfree]�� taken[pairwith]�� ¦������
			ret += countPairings(taken); // ��� ¦�� ���� ��츦 ������ ������ ¦�� ���°�츦 ���.
			taken[firstfree] = taken[pairwith] = false;// taken[firstfree]�� taken[pairwith]�� �ƴ� �ٸ� ¦�� ���� ��츦 ����ϱ����� false��
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
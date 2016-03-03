#include <iostream>
#include <vector>

using namespace std;

//��ǥ�� �������� ������ ��ǥ ����

int coverType[4][3][2] = {
		{ { 0, 0 }, { 0, 1 }, { 1, 0 } },
		{ { 0, 0 }, { 0, 1 }, { 1, 1 } },
		{ { 0, 0 }, { 1, 0 }, { 1, 1 } },
		{ { 0, 0 }, { 1, -1 }, { 1, 0 } }
};

// int type�� ������ ���� Ÿ��(4��1), delta = 1�ϰ�� ������ ī��Ʈ ����, delta = -1�� ��� ������ ī��Ʈ ����. �� �� ���� ������ �ʾ��� ��� ������ ����.
bool set(vector<vector<int>>& board, int y, int x, int type, int delta){
	bool ok = true;

	for (int i = 0; i < 3; i++){
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[y].size())
			ok = false; // �������� �ٸ� ��ǥ���� �������� �������� false;
		else if ((board[ny][nx] += delta) > 1) //�̹� ������ ���� �� �����������.
			ok = false;
	}

	return ok;
}








int cover(vector<vector<int>>& board){
	// ���� ������ �����Ͽ� �������� �ʴ� ���� �˻�.
	int y = -1, x = -1;
	//y��
	for (int i = 0; i < board.size(); i++){
		//x��
		for (int j = 0; j < board[i].size(); j++){
			if (board[i][j] == 0) { // board[i][j] == 0 -> �������� ����.
				y = i;
				x = j;
				break; //ù��° ������ �ȵ����� ��ǥ�� ã�ұ⶧���� break;
			}

		}
		if (y != -1) break; //���� ��ġ�� ã�������̸�
	}

	//������� : ��ĭ�� ���ٴ°� ���ĭ�� ä���ٴ� ���̹Ƿ� 1�� ��ȯ.
	if (y == -1) return 1;

	int ret = 0;

	for (int type = 0; type < 4; type++){
		if (set(board, y, x, type, 1)){ //�� ���� �������� �־������.
			ret += cover(board); // �� �������� �����´�.
		}
		set(board, y, x, type, -1); // ���� Ÿ���� ���� �������� ���.
	}

	return ret;

}

int main(){
	int testcase, h, w;
	char input;
	cin >> testcase;
	while (testcase--){

		cin >> h >> w;
		vector<vector<int>> board(h, vector<int>(w, 0)); // 2���� �����迭(2���� ����) ����

		//2���� ���Ϳ� ������ �Է�. #�ϰ�� true, .�ϰ�� false
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				cin >> input;
				if (input == '#')
					board[i][j] = 1;
				else
					board[i][j] = 0;
			}
		}

		//������ ������ �����ϴ� �Լ��� ȣ���Ͽ� ��ȯ�� ���.
		cout << cover(board) << endl;
	}
}
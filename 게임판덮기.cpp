#include <iostream>
#include <vector>

using namespace std;

//좌표를 기준으로 뒤집을 좌표 설정

int coverType[4][3][2] = {
		{ { 0, 0 }, { 0, 1 }, { 1, 0 } },
		{ { 0, 0 }, { 0, 1 }, { 1, 1 } },
		{ { 0, 0 }, { 1, 0 }, { 1, 1 } },
		{ { 0, 0 }, { 1, -1 }, { 1, 0 } }
};

// int type은 뒤집을 판의 타입(4택1), delta = 1일경우 뒤집은 카운트 증가, delta = -1인 경우 뒤집은 카운트 제거. 즉 그 판을 뒤집지 않았을 경우 연산을 위해.
bool set(vector<vector<int>>& board, int y, int x, int type, int delta){
	bool ok = true;

	for (int i = 0; i < 3; i++){
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[y].size())
			ok = false; // 기점으로 다른 좌표들이 보드판을 벗어났을경우 false;
		else if ((board[ny][nx] += delta) > 1) //이미 뒤집힌 판을 또 뒤집었을경우.
			ok = false;
	}

	return ok;
}








int cover(vector<vector<int>>& board){
	// 왼쪽 위부터 시작하여 뒤집히지 않는 블럭을 검색.
	int y = -1, x = -1;
	//y열
	for (int i = 0; i < board.size(); i++){
		//x열
		for (int j = 0; j < board[i].size(); j++){
			if (board[i][j] == 0) { // board[i][j] == 0 -> 뒤집히지 않음.
				y = i;
				x = j;
				break; //첫번째 왼쪽위 안뒤집힌 좌표를 찾았기때문에 break;
			}

		}
		if (y != -1) break; //만약 위치를 찾은상태이면
	}

	//기저사례 : 빈칸이 없다는건 모든칸을 채웠다는 듯이므로 1을 반환.
	if (y == -1) return 1;

	int ret = 0;

	for (int type = 0; type < 4; type++){
		if (set(board, y, x, type, 1)){ //그 판이 뒤집을수 있었을경우.
			ret += cover(board); // 그 나머지를 뒤집는다.
		}
		set(board, y, x, type, -1); // 다음 타입을 위해 뒤집은걸 취소.
	}

	return ret;

}

int main(){
	int testcase, h, w;
	char input;
	cin >> testcase;
	while (testcase--){

		cin >> h >> w;
		vector<vector<int>> board(h, vector<int>(w, 0)); // 2차원 동적배열(2차원 벡터) 생성

		//2차원 벡터에 데이터 입력. #일경우 true, .일경우 false
		for (int i = 0; i < h; i++){
			for (int j = 0; j < w; j++){
				cin >> input;
				if (input == '#')
					board[i][j] = 1;
				else
					board[i][j] = 0;
			}
		}

		//뒤집는 연산을 실행하는 함수를 호출하여 반환값 출력.
		cout << cover(board) << endl;
	}
}
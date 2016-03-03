#include <iostream>
#include <string>
#include <vector>
using namespace std;

int cache[101][101];


string W, S;


int match(int w, int s) {

	int& ret = cache[w][s];
	if (ret != -1) return ret;

	//와일드카드 문자열이 끝에 도달하지 않았을경우, 문자열이 끝에 도달하지 않았을경우 w가 ?이거나 두 문자가 같을경우 계속 진행
	while (w < W.size() && s < S.size() &&( W[w] == '?' || W[w] == S[s])) {
		++w;
		++s;
	}

	if (W.size() == w) return ret = (S.size() == s ? 1:0); //b도 문자열 끝까지 도달해야 true 아니면 false


	//만약 *을 만났다면, 그 이후를 검사.
	if (W[w] == '*') {
		for (int skip = 0; s+skip <= S.size(); ++skip) {
			//substr의 length가 문자열을 벗어나면 가장 끝 문자 위치를 가르키게된다.
			// '*'문자 다음의 문자와 일치하는 문자가 나타나는지 계속해서 비교.
			if (match(w + 1, s + skip)) {
				return ret = 1;
			}
		}
	}

	return 0;
}


int match2(int w, int s) {

	int& ret = cache[w][s];
	if (ret != -1) return ret;

	//와일드카드 문자열이 끝에 도달하지 않았을경우, 문자열이 끝에 도달하지 않았을경우 w가 ?이거나 두 문자가 같을경우 계속 진행
	if (w < W.size() && s < S.size() && (W[w] == '?' || W[w] == S[s]))
		ret = match2(w + 1, s + 1);

	if (W.size() == w) return ret = (S.size() == s ? 1 : 0); //b도 문자열 끝까지 도달해야 true 아니면 false


															 //만약 *을 만났다면, 그 이후를 검사.
	if (W[w] == '*') {
		//*을 무시하고 넘어갔을때의 경우와 *을 고려했을때 중 하나라도 가능하면 1반환
		if(match2(w+1,s) ||(s<S.size() && match(w,s+1))
				return ret = 1;
		}
	}

	return 0;
}


vector<string> output;

int main() {

	int i = 3;
	cin >> W;
	while (i--) {
		cin >> S;
		memset(cache, -1, sizeof(cache));
		int test = match(0, 0);
		if(test == 1) output.push_back(S);
	}

	printf("\n");
	for (int i = 0; i <= output.size(); i++) {
		cout << output.back() << endl;
		output.pop_back();
	}
}
#include <iostream>
#include <vector>
#include <cmath>

#define min(x,y) (((x)<(y))?(x):(y))
using namespace std;

// 외판원 문제를 완전 탐색 방법으로 풀어보자.

int n;


double shortestPath(vector<vector<double>>& dist, vector<int> path, vector<bool>visited, double currentLength){

	//기저 사례 : 모든 순회를 다 했을경우.
	if (path.size() == n)
		return currentLength;

	double ret = 987654321;

	for (int next = 0; next < n; next++){
		if (visited[next]) // 방문한 곳이라면
			continue;

		int here = path.back();
		path.push_back(next);
		visited[next] = true;
		double cand = shortestPath(dist, path, visited, currentLength + dist[here][next]);
		ret = min(ret, cand);
		visited[next] = false;
		path.pop_back();
	}

	return ret;
}

int main(){

	int testcase;
	cin >> testcase;
	while (testcase--){
		double ret = 987654321;
		cin >> n;
		vector<vector<double>> dist(n, vector<double>(n, 0));
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				cin >> dist[i][j];
			}
		}
		for (int i = 0; i < n; i++){
			vector<int> path(1, i); // 경로를 저장할 벡터 맨처음 도시 선택.
			vector<bool> visited(n, false); // 방문 여부를 저장할 벡터.
			visited[i] = true; // 출발 도시 방문여부 체크.
			ret = min(shortestPath(dist, path, visited, 0), ret);
		}

		cout << ret << endl;
	}

}
#include <iostream>
#include <vector>
#include <cmath>

#define min(x,y) (((x)<(y))?(x):(y))
using namespace std;

// ���ǿ� ������ ���� Ž�� ������� Ǯ���.

int n;


double shortestPath(vector<vector<double>>& dist, vector<int> path, vector<bool>visited, double currentLength){

	//���� ��� : ��� ��ȸ�� �� �������.
	if (path.size() == n)
		return currentLength;

	double ret = 987654321;

	for (int next = 0; next < n; next++){
		if (visited[next]) // �湮�� ���̶��
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
			vector<int> path(1, i); // ��θ� ������ ���� ��ó�� ���� ����.
			vector<bool> visited(n, false); // �湮 ���θ� ������ ����.
			visited[i] = true; // ��� ���� �湮���� üũ.
			ret = min(shortestPath(dist, path, visited, 0), ret);
		}

		cout << ret << endl;
	}

}
#include <iostream>
#include <vector>
using namespace std;

int testcase,n,d,p,t,q[50],A[50][50];
int route[50];//경로의 갯수를 저장하는 배열 
double numb3rs(vector<int>& path,int city){
	double ret1 = 1;
	if(path.size()==d+1) {
		if(path.back() != city)
			return 0;
			//도착하는 위치의 확률은 계산할 필요가 없다. 
		for(int i = 0; i<path.size()-1;i++)
			ret1/=route[path[i]]; 
		return ret1;
	}
	
	double ret2 = 0;
	int curCity = path.back();
	for(int i = 0; i<n;i++){
		//만약 산길이 존재하면 
		if(A[curCity][i]==1){
			//그 도시를 벡터에 넣고 진행한다. 
			path.push_back(i);
			ret2 += numb3rs(path,city);
			//다음 진행을 위해 다시 빼낸다. 
			path.pop_back();
		}
	}	
	return ret2; 
}
int main(){
	cin >>testcase;
	while(testcase--){
		cin >> n >> d >> p;
		
		//배열 초기화 
		for(int i = 0; i< n; i++){
			route[i] = 0;//해당 도시의 경로 갯수 초기화 
			for(int j = 0; j<n;j++){
				cin>>A[i][j];
				if(A[i][j] == 1)
					route[i]+=1;//경로 갯수 추가 
			}
		}
		
		cin>>t; // 확인할 도시 갯수 
		for(int i = 0; i<t;i++)
			cin>>q[i];//확인할 도시 초기화
		
		vector<int> path;// 경로를 저장할 벡터 
		path.push_back(p);//교도소 위치 삽입 
		cout.precision(7);
		for(int i = 0; i<t;i++) 
			cout<<numb3rs(path,q[i])<<' ';
			
	}
}

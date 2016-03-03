#include <iostream>
#include <cstring>
using namespace std;

int testcase,n,d,p,t,q[51],A[51][51];
int route[51];//경로의 갯수를 저장하는 배열 
double cache[51][101];
double numb3rs(int here,int day,int city){
	if(day==0) {
		if(here != city)
			return 0;
		return 1;
	}
	double& ret = cache[here][day];
	if(ret!=-1) return ret;
	
	ret = 0;
	for(int next = 0; next<n;next++){
		//만약 산길이 존재하면 
		if(A[here][next]==1){
			//그 도시를 벡터에 넣고 진행한다. 
			ret += numb3rs(next,day-1,city)/route[next];
			//다음 진행을 위해 다시 빼낸다. 
		}
	}	
	return ret; 
}
int main(){
	cin >>testcase;
	while(testcase--){
		for(int j = 0; j<51; j++)
			for(int k = 0 ; k<101;k++)
				cache[j][k]=-1;
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
			
		cout.precision(8);
		for(int i = 0; i<t;i++) {
		
	 		cout<<numb3rs(q[i],d,p)<<' ';
		}
		cout<<endl;
	}
}

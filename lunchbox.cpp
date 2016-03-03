#include <iostream>
#include <algorithm>
#include <vector> 
#include <utility>
using namespace std;
int c,n,m[10000],e[10000];

int heat(){
	vector<pair<int,int> > order;
	for(int i=0; i<n; ++i){
		order.push_back(make_pair(-e[i],i));//-e[i]를 기준으로 오름차순 정렬을 해서 e[i]가 큰값을 맨 앞에 오도록 한다. 
	}
	sort(order.begin(),order.end());
	int ret=0, beginEat=0;
	for(int i=0; i<n;i++){
		int box = order[i].second;
		beginEat +=m[box];
		ret = max(ret,beginEat +e[box]); //데우고 먹는시간보다 그 전에 음식 먹는 시간이 더 오래걸릴경우 고려. 
	}
	 return ret; 
} 
int main(){
	cin>>c;
	while(c--){
		int sum=0;
		cin >> n;
		for(int i=0; i<n;i++){
			cin>>m[i];
			sum+=m[i];
		}
		for(int i=0; i<n;i++)
			cin>>e[i];
			//맨 마지막에 먹는 음식의 먹는 시간 + 전체 데우는 시간(전체 데우는 시간은 똑같으므로) 
			//이 방법 외에 먹는데 가장 오래걸리는걸 가장 먼저 데피는 방법이 있다. 
		cout<<heat()<<endl;
	}
}

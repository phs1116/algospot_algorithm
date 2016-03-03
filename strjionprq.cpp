#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
int c,n;
int mincat(vector<int>& len){
	int ret = 0;
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=0; i<n;i++)
		pq.push(len[i]);
	
	while(pq.size()>1){
		int a = pq.top();pq.pop();
		int b=  pq.top();pq.pop();
		ret +=a+b;
		pq.push(a+b);
	}
	
	return ret;
}
int main(){
	cin>>c;
	while(c--){
		cin>>n;
		vector<int> len(n);
		for(int i=0; i<n;i++)
			cin>>len[i];
			
		cout<<mincat(len)<<endl;
	}
}	

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
int c,n;
int mincat(vector<int>& len){
	int ret = 0;
	while(true){
		if(len.size() == 1)
			return ret;
		sort(len.begin(),len.end(),greater<int>());
		int a = len.back();len.pop_back();
		int b=  len.back(); len.pop_back();
		ret +=a+b;
		len.push_back(a+b);
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
